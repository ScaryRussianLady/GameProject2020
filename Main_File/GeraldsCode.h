#pragma once
//Beginning of code by [Gerald] with help from [Annija Balode 9102828].
    /*while (true)
    {
        singularWordOutput("\nWhich one will it be?\n");
        std::cin.getline(typeOfClan, 25);
        if (strcmp(typeOfClan, "attack") == 0) {
            singularWordOutput("Good, strong choice!");

            break;
        }
        else if (strcmp(typeOfClan, "Attack") == 0) {
            singularWordOutput("Good, strong choice!");

            break;
        }
        else if (strcmp(typeOfClan, "ATTACK") == 0) {
            singularWordOutput("Good, strong choice!");

            break;
        }


        if (strcmp(typeOfClan, "defence") == 0) {
            singularWordOutput("All nations need defending!");

            break;
        }
        else if (strcmp(typeOfClan, "Defence") == 0) {
            singularWordOutput("All nations need defending!");

            break;
        }
        else if (strcmp(typeOfClan, "DEFENCE") == 0) {
            singularWordOutput("All nations need defending!");

            break;
        }
        else {
            singularWordOutput("Sorry that was not an option, please try again.\n");
            char typeOfClan[25];
            continue;
        }
    }*/
    //End of code by [Gerald] with help from [Annija Balode 9102828].



/*std::string save_data()
{
    //attempt
    std::cout << "saving game progress...please finalise details" << std::endl;
    std::string clan_name2;
    std::cout << "Enter Clan name?" << std::endl;
    std::cin >> clan_name2;

    std:: string typeOfClan2;
    std::cout << "Choose Attack or Defence";
    std::cin >> typeOfClan2;

    std::ofstream file_("PlayerData.txt");

    if(file_.is_open()){

    file_<< clan_name2;
    file_<< typeOfClan2;
    }
    std::cin.get();
    return 0;
}

std::string load_data()
{
    std::ifstream file_("PlayerData.txt");
    std::string clan_name = test.getClanName;
    std::string type_clan = test.getClanType;

    if (file_.is_open())
    {

        while(file_>> nameOfClan >>typeOfClan)
            {
                std::cout << " Current saved progress: ";
                std::cout<<nameOfClan<<" " typeOfClan<<'\n';
            }
        file_.close();
    }

    else
    {
        std::cout<<"file is not open"<< '\n';
        std::cin.get();
        return 0;
    }

}
*/