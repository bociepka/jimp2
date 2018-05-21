//
// Created by Bartek on 22.05.2018.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include<iostream>
#include<string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include <set>
#include <map>
#include <functional>
#include <experimental/optional>
#include <cstdlib>
#include <algorithm>


namespace academia{

    class SchedulingItem {
    public:
        SchedulingItem(){};
        virtual ~SchedulingItem(){};
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year): course_id(course_id), teacher_id(teacher_id), room_id(room_id), time_slot(time_slot), year(year) {};
        SchedulingItem(std::vector<int> vec): vec_(vec){};
        int CourseId()const;
        int TeacherId()const ;
        int RoomId()const;
        int TimeSlot()const;
        int Year()const;
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
        std::vector<int> vec_;

    };

    class Schedule {
    public:
        Schedule(){};
        Schedule(std::vector<SchedulingItem> slist):schedulingitem_list_(slist){};
        virtual ~Schedule(){};
        SchedulingItem operator[]( const int idx)const;

        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
    private:
        std::vector<SchedulingItem> schedulingitem_list_;
    };





    class  Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);



    private:
        std::vector<int> rooms;
        std::map<int, std::vector<int>> teacher_courses_assignment;
        std::map<int, std::set<int>>courses_of_year;
        int n_time_slots;
    };

    class  NoViableSolutionFound {
    public:
        NoViableSolutionFound(){};
        ~NoViableSolutionFound(){};

    };
    class GreedyScheduler:public Scheduler{
    public:

    };

}

#endif //JIMP_EXERCISES_SCHEDULER_H
