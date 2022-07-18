
#include "lib.h"
#include <stdio.h>

void set_gender(unsigned short* info, enum Gender v)
{
    *info &= 0xFFFE;
    *info |= v;
}

void set_age(unsigned short* info, unsigned age)
{
    *info &= 0xFF01;
    *info |= age << 1;
}

void set_education(unsigned short* info, enum Education v)
{
    *info &= 0xFCFF;
    *info |= v << 8;
}

void set_hair_color(unsigned short* info, enum HairColor v)
{
    *info &= 0xF3FF;
    *info |= v << 10;
}

void set_mar_status(unsigned short* info, enum MarStatus v)
{
    *info &= 0xEFFF;
    *info |= v << 11;
}

void set_pet_status(unsigned short* info, enum PetStatus v)
{
    *info &= 0xDFFF;
    *info |= v << 12;
}

void set_fav_sport(unsigned short* info, enum FavSport v)
{
    *info &= 0x3FFF;
    *info |= v << 14;
}


//-------------------------------------------------------------------


enum Gender get_gender(unsigned short info)
{
    return Gender(info & 1);
}

unsigned get_age(unsigned short info)
{
    return (info >> 1) & 0x007F;
}

enum Education get_education(unsigned short info)
{
    return Education((info >> 8) & 0x0003);
}

enum HairColor get_hair_color(unsigned short info)
{
    return HairColor((info >> 10) & 0x0003);//--------------------------
}

enum MarStatus get_mar_status(unsigned short info)
{
    return MarStatus((info >> 12) & 0x0001);//-----------------------
}

enum PetStatus get_pet_status(unsigned short info)
{
    return PetStatus((info >> 13) & 0x0001);
}

enum FavSport get_fav_sport(unsigned short info)
{
    return FavSport((info >> 14));
}

void print_all(unsigned short info)
{
    enum Gender gender = get_gender(info);
    unsigned age = get_age(info);
    enum Education education = get_education(info);
    enum HairColor hair_color = get_hair_color(info);
    enum MarStatus mar_status = get_mar_status(info);
    enum PetStatus pet_status = get_pet_status(info);
    enum FavSport fav_sport = get_fav_sport(info);


    printf("Gender: %s "
        "Age: %d "
        "Education: %s "
        "Hair: %s "
        "MarStatus: %s",
        "PetStatus: %s",
        "FavSport: %s",
        str_gender(gender),
        age,
        str_education(education),
        str_hair_color(hair_color),
        str_mar_status(mar_status),
        str_pet_status(pet_status),
        str_fav_sport(fav_sport));
}

const char* str_gender(enum Gender v)
{
    switch (v) {
    case GenderMale: return "Male";
    case GenderFemale: return "Female";
    }
}

const char* str_education(enum Education v)
{
    switch (v) {
    case EducationNone: return "None";
    case EducationSubmiddle: return "Submiddle";
    case EducationMiddle: return "Middle";
    case EducationHigh: return "High";
    }
}

const char* str_hair_color(enum HairColor v)
{
    switch (v) {
    case HairColorNone: return "None";
    case HairColorBlack: return "Black";
    case HairColorWhite: return "White";
    case HairColorRed: return "Red";
    }
}

const char* str_mar_status(enum MarStatus v)
{
    switch (v) {
    case MarStatusBusy: return "Busy";
    case MarStatusFree: return "Free";
    }


}

const char* str_pet_status(enum PetStatus v)
{
    switch (v) {
    case PetStatusNo: return "No";
    case PetStatusYes: return "Yes";
    }
}

const char* str_fav_sport(enum FavSport v)
{
    switch (v) {
    case FavSportFootball: return "Football";
    case FavSportBascketball: return "Bascketball";
    case FavSportHockey: return "Hockey";
    case FavSportVolleyball: return "Volleyball";
    }
}