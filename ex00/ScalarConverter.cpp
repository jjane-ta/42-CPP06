#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
	struct Checker
	{
		static bool isDouble(std::string digits)
		{
			char *ptr;
			strtod(digits.c_str(), &ptr);
			return !digits.empty() && (*ptr) == '\0';
		}
		static bool isFloat(std::string digits)
		{
			return digits[digits.length() - 1] == 'f' && Checker::isDouble(digits.substr(0, digits.length() - 1));
		}
		static bool isNumber(std::string digits)
		{
			return Checker::isDouble(digits) || Checker::isFloat(digits);
		}
		static bool isChar(std::string digits)
		{
			double d = atof(digits.c_str());
			return (Checker::isInt(digits) && d >= 0 && d <= static_cast<unsigned char>(-1));
		}
		static bool isInt(std::string digits)
		{
			double d = atof(digits.c_str());
			return (Checker::isNumber(digits) && !isnan(d));
		}
	};

	struct Converter
	{
		static std::string toDigits(std::string literal)
		{
			std::stringstream ss;
			literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))
					? ss << static_cast<int>(literal[0])
					: ss << literal;
			return ss.str();
		}
		static std::string toChar(std::string digits)
		{
			unsigned char c = static_cast<unsigned char>(atof(digits.c_str()));
			return !Checker::isChar(digits)
			? "impossible" : !std::isprint(c)	
				? "Non displayable"	: '\'' + std::string(1, c) + '\'' ;
		}
		static std::string toInt(std::string digits)
		{
			std::stringstream ss;
			double d = atof(digits.c_str());
			int i = static_cast<int>(d);
			ss << i;
			return !Checker::isNumber(digits) || isnan(d) || isinf(d)
			? "impossible" : (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
				? "overflow" : ss.str();
		}
		static std::string toFloat(std::string digits)
		{
			std::stringstream ss;
			double d = atof(digits.c_str());
			float f = static_cast<float>(d);
			ss.precision(1);
			ss << std::fixed << f;
			return !Checker::isNumber(digits)
				? "impossible" : ((d > -std::numeric_limits<float>::max() && d < std::numeric_limits<float>::max()) || isnan(d)
				? ss.str() : d > 0 ? "inf": "-inf") + 'f' ;
		}
		static std::string toDouble(std::string digits)
		{
			std::stringstream ss;
			double d = atof(digits.c_str());
			ss.precision(1);
			ss << std::fixed << d;
			return !Checker::isNumber(digits) ? "impossible" : ss.str() ;
		}
	};

	std::string digits = Converter::toDigits(literal);
	if (Checker::isFloat(digits))	digits[digits.length() - 1] = 0; // remove final f

	std::cout << "char: " << Converter::toChar(digits) << std::endl;
	std::cout << "int: " << Converter::toInt(digits) << std::endl;
	std::cout << "float: " << Converter::toFloat(digits) << std::endl;
	std::cout << "double: " << Converter::toDouble(digits) << std::endl;
}