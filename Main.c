#include<stdlib.h>
#include <stdio.h>
#include "lib.h"


int main()
{
    unsigned short* peopleArr;
    peopleArr = (unsigned short*)malloc(sizeof(unsigned short));

    int peopleCount = 0;
    Gender gender;
    short age;
    Education education;
    HairColor hair;
    MarStatus marry;
    PetStatus pet;
    FavSport sport;
    short check = 0;

    do
    {
        printf("Input gender (0 - male, 1 - female): ");
        scanf_s("%d", &gender);
        set_gender(&peopleArr[peopleCount - 1], gender);

        printf("Input age: ");
        scanf_s("%d", &age);
        set_age(&peopleArr[peopleCount - 1], age);

        printf("Input education (0 - None  , 1 - Submiddle, 2 - Middle, 3 - High): ");
        scanf_s("%d", &education);
        set_education(&peopleArr[peopleCount - 1], education);

        printf("Input hair color (0 - None, 1 - Black, 2 - White, 3 - Red): ");
        scanf_s("%d", &hair);
        set_hair_color(&peopleArr[peopleCount - 1], hair);

        printf("Input marital status (0 - Free, 1 - Busy): ");
        scanf_s("%d", &marry);
        set_mar_status(&peopleArr[peopleCount - 1], marry);

        printf("Input pet status (0 - None, 1 - Yes): ");
        scanf_s("%d", &pet);
        set_pet_status(&peopleArr[peopleCount - 1], pet);

        printf("Input favourite sport (0 - Football, 1 - Bascketball, 2 - Hockey, 3 - Volleyball): ");
        scanf_s("%d", &sport);
        set_fav_sport(&peopleArr[peopleCount - 1], sport);
        
        printf("Would you like to add a new person? [0 - no, 1 - yes]: ");
        scanf_s("%d", &check);

        if (check == 1)
        {
            peopleCount++;
            peopleArr = (unsigned short*)realloc(peopleArr,peopleCount * sizeof(unsigned short));
        }
        else break;

    } while (check != 0);

    
    printf("People list:\n");
    for (int i = 0; i < peopleCount; i++)
    {
        printf("%d)", i+1);
        print_all(peopleArr[i]);
    }
    
    free(peopleArr);
    return 0;
}