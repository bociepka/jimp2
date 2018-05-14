//
// Created by Bartek on 08.05.2018.
//

#include "Serialization.h"

academia::Room::Room(int id_) : id_(id_) {}
academia::Room::Room(const std::string &name_) : name_(name_) {}
academia::Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}
academia::Room::~Room() {}

std::string academia::Room::TypeToString(academia::Room::Type type) const {
    if(type == Type::COMPUTER_LAB)
            return "COMPUTER_LAB";
    else if (type == Type::LECTURE_HALL)
            return "LECTURE_HALL";
    else if (type == Type::CLASSROOM)
            return "CLASSROOM";
    }

void academia::Room::Serialize(Serializer *serializer) const {
    serializer->Header("room");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->StringField("type", TypeToString(type_));
    serializer->Footer("room");
}

academia::Serializer::Serializer() {}
academia::Serializer::~Serializer() {}
academia::Serializer::Serializer(std::ostream *out): out_(out) {}


academia::DummySerializer::DummySerializer(std::ostream *out) : Serializer(out) {}
academia::DummySerializer::~DummySerializer() {}


academia::Building::Building() {}
academia::Building::~Building() {}

void academia::Building::Serialize(Serializer *serializer) const {
    std::vector<std::reference_wrapper<const Serializable>> rooms2;
    for(const Room &r : rooms_){
        rooms2.emplace_back(r);
    }

    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", rooms2);
    serializer->Footer("building");
}

int academia::Building::Id() const{
    return id_;
}


academia::XmlSerializer::XmlSerializer() {}
academia::XmlSerializer::~XmlSerializer() {}
academia::XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    std::string helper ="<"+field_name+">";
    *out_<<helper<<value<<"<\\"+field_name+">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    std::string helper ="<"+field_name+">";
    *out_<<helper<<value<<"<\\"+field_name+">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {}
void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    *out_ << "<" + field_name + ">";
    value.Serialize(this);
    *out_ << "<\\" + field_name + ">";
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                               const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    std::string helper = "<"+field_name+">";
    *out_<<helper;
    bool is_first = true;
    for(const Serializable &a: value){
        if (is_first){
            is_first= false;
        }else{
        }
        a.Serialize(this);
    }

    *out_<<"<\\"+field_name+">";

}
void academia::XmlSerializer::Header(const std::string &object_name) {
    *out_<<"<"+object_name+">";
}
void academia::XmlSerializer::Footer(const std::string &object_name) {
    *out_<<"<\\"+object_name+">";

}






academia::JsonSerializer::JsonSerializer() {}
academia::JsonSerializer::~JsonSerializer() {}
academia::JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    std::string helper="\""+field_name+"\": ";
    *out_ << helper <<value;
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {}
void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    std::string helper="\""+field_name+"\": ";
    std::string helper2="\""+value+"\"";
    if(value=="buildings"){
        *out_<<helper<<helper2;
    }else{
        *out_<<", "<<helper<<helper2;
    }
}
void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {}
void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    std::string helper="";
    if(field_name=="buildings"){
        helper = "\""+field_name+"\": ";
    }else{
        helper = ", \""+field_name+"\": ";
    }
    *out_<<helper + "[";
    bool is_first = true;
    for(const Serializable &a: value){
        if (is_first){
            //*out_<<", ";
            is_first= false;

        }else{
            *out_<<", ";
        }
        a.Serialize(this);
    }
    *out_<<"]";

}

void academia::JsonSerializer::Header(const std::string &object_name) {
    *out_  << "{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    *out_ << "}";
}



academia::BuildingRepository::BuildingRepository(const std::initializer_list <Building> &building_list): buildings_(building_list){}

void academia::BuildingRepository::Add(const Building &building) {
    buildings_.emplace_back(building);
}

std::experimental::optional <academia::Building> academia::BuildingRepository::operator[](int size) const{
    std::experimental::optional <Building> answer;
    for(auto &m: buildings_){
        if(m.Id()== size){
            answer = std::experimental::make_optional(m);
            return answer;
        }
    }
    Building building;
    answer= std::experimental::make_optional(building);
    return answer;
}

void academia::BuildingRepository::StoreAll(Serializer *serializer) const {
    serializer->Header("building_repository");
    std::vector<std::reference_wrapper<const academia::Serializable>> helping_buildings;
    for(const auto &m: buildings_){
        helping_buildings.emplace_back(m);
    }
    serializer->ArrayField("buildings",helping_buildings);
    serializer->Footer("building_repository");
}

