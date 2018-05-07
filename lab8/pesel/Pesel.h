//
// Created by Bartek on 24.04.2018.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include <stdexcept>


namespace academia {
    class Pesel {
    public:
        Pesel();

        ~Pesel();

        Pesel(const char *pesel);

        void validatePESEL(const char*);

    private:
        const char *pesel_;
    };
    class InvalidPeselChecksum: public std::invalid_argument{
    public:
        InvalidPeselChecksum(std::string input, int k);
    };
    class InvalidPeselLength: public std::invalid_argument{
    public:
        InvalidPeselLength(std::string input, int length);
    };
    class InvalidPeselCharacter: public std::invalid_argument{
    public:
        InvalidPeselCharacter(std::string input, int k);
    };
    class AcademiaDataValidationError: public std::invalid_argument{
    public:
        AcademiaDataValidationError(std::string , int k);
    };
}

#endif //JIMP_EXERCISES_PESEL_H
