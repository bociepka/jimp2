//
// Created by Bartek on 08.05.2018.
//

#ifndef JIMP_EXERCISES_ACADEMIASERIALIZER_H
#define JIMP_EXERCISES_ACADEMIASERIALIZER_H
#include<iostream>
#include<string>
#include <vector>
#include <experimental/optional>
#include <iostream>
#include <string.h>
#include <functional>
#include <vector>
#include <list>

namespace academia {
    class Serializable;
    class Serializer{
    public:
        //std::vector<std::reference_wrapper<Room>> objects_;
        Serializer();
        Serializer( std::ostream *out);
        virtual ~Serializer();


        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;


    protected:
        std::ostream *out_;
    };

    class Serializable{
    public:
        virtual void Serialize(Serializer *ser) const=0;
//        virtual ~Serializable();

    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(){};
        Room(int id_);
        Room(int id_, const std::string &name_, Type type_);
        Room(const std::string &name_);
        virtual ~Room();
        void Serialize(Serializer * serializer) const override;
        std::string TypeToString(Type type) const;

    private:
        int id_;
        std::string name_;
        Type type_;

    };

    class Building : public Serializable{
    public:
        Building();
        Building(int id, std::string number, std::initializer_list <Room> room):
                id_(id), name_(number), rooms_(room){} ;
        virtual ~Building();
        void Serialize(Serializer * serializer) const override;
        int Id() const;

    protected:
        int id_;
        std::string name_;
        std::vector <Room> rooms_;
    };



    class DummySerializer:public Serializer{
    public:
        DummySerializer(std::ostream *out);

        virtual ~DummySerializer();
    };



    class XmlSerializer: public Serializer {
    public:
        XmlSerializer();
        XmlSerializer(std::ostream *out);
        virtual ~XmlSerializer();

        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    private:
    };

    class JsonSerializer: public Serializer {
    public:
        JsonSerializer();
        JsonSerializer(std::ostream *out);
        virtual ~JsonSerializer();
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    };


    class BuildingRepository{
    public:
        BuildingRepository(){};
        //BuildingRepository(Building building);
        BuildingRepository(const std::initializer_list<Building> &building_list);
        void StoreAll(Serializer *serializer) const;
        void Add(const Building &building);
        std::experimental::optional  <Building>  operator[](int size) const;
        ~BuildingRepository(){};
        std::vector <Building>  buildings_;
        Building single_building_;


    };

}

#endif //JIMP_EXERCISES_ACADEMIASERIALIZER_H
