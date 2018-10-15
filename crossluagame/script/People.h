#pragma once

#include <string>

namespace lw {
	class Student
	{
	private:
		std::string _name;
		int _tag;
		int _sex;

	public:
		Student();
		virtual ~Student();

	public:
		void setName(const std::string& name);
		std::string getName();

		void setTag(int tag);
		int getTag();

		void setSex(int sex);
		int getSex();
	};

	namespace user {
		
		class People {
		private:
			std::string _name;
			int _tag;
			int _sex;

		public:
			People();
			People(const std::string& name, int tag, int sex);
			virtual ~People();

		public:
			void setName(const std::string& name);
			std::string getName();

			void setTag(int tag);
			int getTag();

			void setSex(int sex);
			int getSex();

		public:
			void printf();
			void printf(const std::string& s);
		};

		class Man : public People
		{
		private:
			int beard;

		public:
			Man();
			~Man();
		};
	}
}
