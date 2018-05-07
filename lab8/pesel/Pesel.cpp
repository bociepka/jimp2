//
// Created by Bartek on 24.04.2018.
//

#include "Pesel.h"

void academia::Pesel::validatePESEL(const char *) {
    int k=0;
    while (pesel_[k]!='\0'){
        k++;
    }
    if (k!=10){
        throw(InvalidPeselLength("Dlugosc",k));
    }
}

academia::InvalidPeselChecksum::InvalidPeselChecksum(std::string input, int k):invalid_argument(input) {

}

academia::InvalidPeselLength::InvalidPeselLength(std::string input, int k):invalid_argument(input) {

}

academia::InvalidPeselCharacter::InvalidPeselCharacter(std::string input, int k):invalid_argument(input) {

}

academia::AcademiaDataValidationError::AcademiaDataValidationError(std::string input, int k):invalid_argument(input) {

}