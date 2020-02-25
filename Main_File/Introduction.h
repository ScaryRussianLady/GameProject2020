#pragma once
#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>

template <typename T>
T get_input(const std::string& strQuery);

std::string get_username();
std::string get_password();
void save_user(const std::string& username, const std::string& password);

void login();
void register_user();
void main_menu();


template <typename T>
T get_input(const std::string& strQuery)
{
    std::cout << strQuery << "\n> ";
    T out = T();

    while (!(std::cin >> out)) {
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << strQuery << "\n> ";
    }

    return out;
}

std::string get_password()
{
    std::string password1 = get_input <std::string>("Please enter your password.");
    std::string password2 = get_input <std::string>("Please re-enter your password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = get_input <std::string>("Please enter your password.");
        password2 = get_input <std::string>("Please re-enter your password.");
    }

    return password1;
}

std::string get_username()
{
    std::string username = get_input <std::string>("Please enter your username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = get_input <std::string>("Please enter your username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}



void main_menu()
{
    system("color 0F");
    int choice = get_input <int>(
        "Welcome to The Gladiator!\nFirst of all, would you like to Login or Register Chief?" "\n"
        "[1] Login" "\n"
        "[2] Register");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
        break;
    }

}

void register_user()
{
    std::string username = get_username();
    std::string password = get_password();
    save_user(username, password);
}

void save_user(const std::string& username, const std::string& password)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);
    file << password << "\n";
}

std::string temp;

void login()
{
    std::string username = get_username();
    std::string password = get_password();
    std::cout << "You are being logged in!\n" << std::endl;
}

//https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program