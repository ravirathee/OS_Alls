#!/bin/bash
#Factorial of a number
fact ()
{
    if [ $1 -gt 1 ]; then
    y=`expr $1 - 1`
    fact $y
    x=$(( $1 * $? ))
    return $x
    else
        return 1
        fi
        }
echo -e "Enter a number : \c"
read num
fact $num
echo "Factorial of $num is $?."
exit 0
OUTPUT
óóóóóó
Ravis-MacBook-Pro:~ ravirathee$
bash a.sh
Enter a number : 5
#Gross Salary
echo -e "Enter ur basic salary \c"
read sal
da=`expr $sal \* 40 / 100`
ha=`expr $sal \* 20 / 100`
Nsal=`expr $sal + $da + $ha`
echo "ur Basic Salary $sal
"
echo "ur Dearness Allowance $da
"
echo "Ur House rent $ha
"
echo "
------------"
echo "Ur Net Salary is Rs. $Nsal
"else
echo "Pls enter basic salary
