#pragma once

enum Gender {
    GenderMale,
    GenderFemale,
};

enum Education {
    EducationNone,
    EducationSubmiddle,
    EducationMiddle,
    EducationHigh
};

enum HairColor {
    HairColorNone,
    HairColorBlack,
    HairColorWhite,
    HairColorRed
};

enum MarStatus {
    MarStatusFree,
    MarStatusBusy
};

enum PetStatus {
    PetStatusNo,
    PetStatusYes
};

enum FavSport {
    FavSportFootball,
    FavSportBascketball, 
    FavSportHockey,
    FavSportVolleyball
};

enum Gender get_gender(unsigned short info);
unsigned get_age(unsigned short info);
enum Education get_education(unsigned short info);
enum HairColor get_hair_color(unsigned short info);
enum MarStatus get_mar_status(unsigned short info);
enum PetStatus get_pet_status(unsigned short info);
enum FavSport get_fav_sport(unsigned short info);

const char* str_gender(enum Gender v);
const char* str_education(enum Education v);
const char* str_hair_color(enum HairColor v);
const char* str_mar_status(enum MarStatus v);
const char* str_pet_status(enum PetStatus v);
const char* str_fav_sport(enum FavSport v);

void print_all(unsigned short info);

void set_gender(unsigned short* info, enum Gender v);
void set_age(unsigned short* info, unsigned age);
void set_education(unsigned short* info, enum Education v);
void set_hair_color(unsigned short* info, enum HairColor v);
void set_mar_status(unsigned short* info, enum MarStatus v);
void set_pet_status(unsigned short* info, enum PetStatus v);
void set_fav_sport(unsigned short* info, enum FavSport v);

