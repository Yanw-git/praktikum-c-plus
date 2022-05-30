#include "parser.h"

#include <string_view>

/**
 * Helper function of parseExpression.
 * Does the parsing of a function expression in prefix notation.
 */
std::unique_ptr<Calculator> parseExpressionRecursive(std::string_view& expr) //expr "~0"...
{
    char op = expr.at(0);
    expr.remove_prefix(1);

    switch (op)
    {
    // TODO: Insert parsing of '&' and '|'
    case '&':
    {
        auto right1 = parseExpressionRecursive(expr);
        auto right2 = parseExpressionRecursive(expr);
        return std::make_unique<AND>(std::move(right1),std::move(right2)); 
      
     }
      case'|':
     {
		auto right1 = parseExpressionRecursive(expr);
        auto right2 = parseExpressionRecursive(expr);
        return std::make_unique<Or>(std::move(right1),std::move(right2));  
        
     }
    case '~':
    {
        auto right = parseExpressionRecursive(expr);
        return std::make_unique<NotCalculator>(std::move(right));
   
	}
    
    
    default:
        return std::make_unique<LeafCalculator>(static_cast<size_t>(std::stoul(std::string(1, op))));
    }
}

/**
 * Parses a boolean function expression in prefix notation.
 * Returns a unique_ptr to a new Calculator for the function expression.
 */
std::unique_ptr<Calculator> parseExpression(const std::string& expr)
{
    std::string_view exprView(expr);
    return parseExpressionRecursive(exprView);
}

