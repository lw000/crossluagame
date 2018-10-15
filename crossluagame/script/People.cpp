#include "People.h"
#include <iostream>

namespace lw {
	Student::Student()
	{
		std::cout << "Student()" << std::endl;
	}

	Student::~Student()
	{
		std::cout << "~Student()" << std::endl;
	}

	void Student::setName(const std::string& name) {
		this->_name = name;
	}

	std::string Student::getName() {
		return this->_name;
	}

	void Student::setTag(int tag) {
		this->_tag = tag;
	}

	int Student::getTag() {
		return this->_tag;
	}

	void Student::setSex(int sex) {
		this->_sex = sex;
	}

	int Student::getSex() {
		return this->_sex;
	}

	namespace user {
		People::People()
		{
			std::cout << "People()" << std::endl;
		}

		People::People(const std::string& name, int tag, int sex) : _name(name), _tag(tag), _sex(sex) {
			std::cout << "People(name, tag, sex)" << std::endl;
		}

		People::~People()
		{
			std::cout << "~People()" << std::endl;
		}

		void People::setName(const std::string& name) {
			this->_name = name;
		}

		std::string People::getName() {
			return this->_name;
		}

		void People::setTag(int tag) {
			this->_tag = tag;
		}

		int People::getTag() {
			return this->_tag;
		}

		void People::setSex(int sex) {
			this->_sex = sex;
		}

		int People::getSex() {
			return this->_sex;
		}

		void People::printf() {
			std::cout << __FILE__ << ":" << __LINE__ << std::endl;
		}

		void People::printf(const std::string& s) {
			std::cout << __FILE__ << ":" << __LINE__ << ":" << s << std::endl;
		}

		Man::Man::Man()
		{
			std::cout << "Man()" << std::endl;
		}

		Man::~Man()
		{
			std::cout << "~Man()" << std::endl;
		}
	}
}
