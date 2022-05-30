#include "calculator.h"

/**
 * Print Calculator to a stream.
 */
std::ostream& operator<<(std::ostream& os, const Calculator& calc)
{
    calc.print(os);
    return os;
}


CalculatorPrinter::CalculatorPrinter(const Calculator& calc, Calculator::TraversalType t) :
    calculator(&calc), type(t)
{}

std::ostream& operator<<(std::ostream& os, const CalculatorPrinter& cp)
{
    cp.calculator->print(os, cp.type);
    return os;
}


LeafCalculator::LeafCalculator(size_t i) : idx(i) {}

bool LeafCalculator::calculate(const std::vector<bool>& input) const
{
    return input[this->idx];
}

void LeafCalculator::print(std::ostream& os, TraversalType) const
{
    os << this->idx;
}


UnaryCalculator::UnaryCalculator(std::unique_ptr<Calculator> in, std::string opSymbol) :
    inner(std::move(in)), op(std::move(opSymbol))
{}

bool UnaryCalculator::calculate(const std::vector<bool>& input) const
{
    return this->operate(this->inner->calculate(input));
}

void UnaryCalculator::print(std::ostream& os, TraversalType type) const
{
    // TODO: Print according to given TraversalType.
    switch(type)
    {
		case TraversalType::Prefix:
		os<<this->op;
		this->inner->print(os,type);
		break;
		case TraversalType::Infix:
	    os<<this->op<<"(";
	    this->inner->print(os,type);
	    os<<")";
	    this->inner->print(os,type);
		break;
	    case TraversalType::Postfix:
        this->inner->print(os, type);
         os << this->op ;
            break;
        case TraversalType::BonusInfix :
            break;
        default: break;
		
    }   
}

NotCalculator::NotCalculator(std::unique_ptr<Calculator> inner) :
    UnaryCalculator(std::move(inner), "~")
{}

// TODO: Implement missing overrides of NotCalculator here
bool NotCalculator::operate(bool input) const{
	   return (!input);
	  
	   //return false;
}




ANDandOr::ANDandOr(std::unique_ptr<Calculator> in1, std::string opSymbol, std::unique_ptr<Calculator> in2):
	inner1(std::move(in1)),op(std::move(opSymbol)),inner2(std::move(in2)) 
{}



// TODO: Implement members of classes for handling AND and OR
bool ANDandOr::calculate(const std::vector<bool>& vec) const
{
	 return this->operate(this->inner1->calculate(vec), this->inner2->calculate(vec));
	 
}

void ANDandOr::print(std::ostream& os, TraversalType type) const
{
	switch (type)
    {
        case TraversalType::Prefix: 
            os << this->op ;
            this->inner1->print(os, type);
            this->inner2->print(os, type);
            break;
        case TraversalType::Infix:
            os << "(";
            this->inner1->print(os, type);
            os << ")" << this->op << "(";
            this->inner2->print(os, type);
            os << ")";
            break;
        case TraversalType::Postfix :
            this->inner1->print(os, type);
            this->inner2->print(os, type);
            os << this->op;
            break;
        case TraversalType::BonusInfix:
	     break;
	    default:break;
	}
}

 bool AND::operate(bool input1,bool input2) const
 {
	 
	 return (input1&&input2);
 }
 
 
AND::AND(std::unique_ptr<Calculator> in1,std::unique_ptr<Calculator>in2):ANDandOr(std::move(in1),"&",std::move(in2)) {}
 
 
 
 bool Or::operate(bool input1,bool input2) const
 {
	 
	 return (input1||input2);
 }
Or::Or(std::unique_ptr<Calculator> in1,std::unique_ptr<Calculator>in2):ANDandOr(std::move(in1),"|",std::move(in2)) {}
