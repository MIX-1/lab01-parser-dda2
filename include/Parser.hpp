// Copyright 2020 MIX-1 <danilonil1@yandex.ru>

#ifndef INCLUDE_JSONPARSER_HPP_
#define INCLUDE_JSONPARSER_HPP_
#pragma once
#include <any>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <Student.h>
using json = nlohmann::json;
using string = std :: string;
using any = std :: any;
using std :: cout;
using std :: setw;
using std :: runtime_error;
using std :: setfill;
using std :: any_cast;

class Parser {
private:
    std::vector<Student> students;
    size_t name_w;
    size_t group_w;
    size_t avg_w;
    size_t debt_w;

public:
    explicit Parser(std::vector<Student>);

    auto Get_Width(const string&) const -> size_t;

    void Set_Width(const string&, size_t);

    auto Get_Vector() const -> std::vector<Student>;

    void Print_students(const Student& student, std::ostream& os) const;

    void Filler_separation(std::ostream& os) const;

    static void Filler(size_t difference, std::ostream& os);

    void Filler_top(std::ostream& os, const Parser& parser) const;

    static Parser From_File(const string&);

    static Parser From_String(const string&);

    friend std::ostream& operator<<(std::ostream&, const Parser&);
};

#endif // INCLUDE_JSONPARSER_HPP_
