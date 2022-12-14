/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
      1. 整数常量位于[0,255]
  2. Function arguments and local variables (no global variables).
      2. 没有全局变量
  3. Unary integer operations ! ~
      3. 一元整数运算：! ~
  4. Binary integer operations & ^ | + << >>
      4. 二元整数运算符：  & ^ | + << >>
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and &  使用~和&实现^
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // a^b = ((~a&b)|(a&~b))
  // a|b = ~(~a&~b)
  return ~(~(~x&y)&~(x&~y));
}
/* 
 * tmin - return minimum two's complement integer  最小补码整数
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // 10000000000
  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number, 
 *     and 0 otherwise 
 * x是最大补码整数 返回1 否则返回0
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int k = x+1;
  int m = k^(~x); //当x是最大补码整数(01111) ~(x+1)=k m=0
  return (!!k)&!m; // !!k是为了排除k=ffffffff的情况
} 
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 * 如果所有奇数位为1 就返回1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   0-31位
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // 构造odd为所有奇数位为1 AA->1010
  int odd =(0xAA<<24)+(0xAA<<16)+(0xAA<<8)+(0xAA);
  // x与odd进行与运算后，看x是否被更改
  return !((x&odd)^odd);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // 取反加1
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // x-0x30>=0 & 0x39-x>=0
  // 10000 & x ->  if x>0 10000&x00000=0
  // 可以通过与Tmin进行与运算检验当前值是正数还是负数,Tmin会转换成无符号数
    // x&Tmin=1->x<0 x&Tmin=0->x>=0
  int Tmin = 1<<31;
  return !((x+~0x30+1)&Tmin)&!((0x39+~x+1)&Tmin);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // result = xy-xz
  // if x=0 !x=0 ~(!x)+1=0 此时输出z
  // if x!=0 !x=1 ~(!x)+1=-1 此时输出y
  x=!!x; // 在c中，!运算，0返回1，非零返回0，因此需要进行两次!运算
  x=(~x)+1;
  return (x&y)+(~x&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signX= (x>>31)&1;
  int signY = (y>>31)&1;
  int signXsubY = ((y+~x+1)>>31)&1;
    // x 和 y异号 且x的符号为1
    // x 和 y 同号，且y-x的符号位为0 
  return (signX&~signY)|(!signXsubY&!(signX^signY));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 * !运算符 正数和负数返回0 0返回1
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int sign = (x>>31)&1; // sign是x的最高位，如果x是负数，sign为1，如果x是整数,sign为0
  int Tmax = ~(1<<31);
    // 如果sign是负数 那么直接返回0
    // 如果x是正数,x+Tmax会溢出，最高位变为1,最终返回0
    // 如果x是0，Tmax>>31是0,最终返回1
  return (sign^1)&((((x+Tmax)>>31)&1)^1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 * 用二进制补码代表x的最小位数
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
// int b16,b8,b4,b2,b1,b0;
//   int sign=x>>31;
//   x = (sign&~x)|(~sign&x);//如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）


// // 不断缩小范围
//   b16 = !!(x>>16)<<4;//高十六位是否有1
//   x = x>>b16;//如果有（至少需要16位），则将原数右移16位
//   b8 = !!(x>>8)<<3;//剩余位高8位是否有1
//   x = x>>b8;//如果有（至少需要16+8=24位），则右移8位
//   b4 = !!(x>>4)<<2;//同理
//   x = x>>b4;
//   b2 = !!(x>>2)<<1;
//   x = x>>b2;
//   b1 = !!(x>>1);
//   x = x>>b1;
//   b0 = x;
//   return b16+b8+b4+b2+b1+b0+1;//+1表示加上符号位
  int b16,b8,b4,b2,b1,b0;
  // 1. 通过sign确定x的正负
  int sign=x>>31; 
  // 2. 如果x是负数，对x按位取反
    // 如果x是正数,sign=0,x=x
    // 如果x是负数，sign=1,x=~sign
  x = (sign&(~x))|(~sign&x);  
  // 3. 高16位
  b16 = !!(x>>16)<<4; // 优先级:!  >>
  x=x>>b16; // 若高16位有1，那么b16=1<<4=16,即x右移16位，接下来计算高16位中的具体位。
  // 4. 低8位
  b8 = !!(x>>8)<<3;
  x=x>>b8;
  // 5. 低4位
  b4 = !!(x>>4)<<2;
  x=x>>b4;
  // 6. 低2位
  b2 = !!(x>>2)<<1;
  x=x>>b2;
  // 7.低1位
  b1 = !!(x>>1);
  x=x>>b1;

  b0=!!x;
  
  return b16+b8+b4+b2+b1+b0+1;// 将获得的最低位相加，再加一位符号位
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for 返回浮点参数f中等同于2*f的位级
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 0x80000000
  unsigned sign = uf>>31; // 符号位
  unsigned exp = uf>>23&0xff;// 阶码 8个1  [23,30]
  unsigned frac = uf&0x7fffff; // 小数字段 23个1 [0,22]
  if (exp==0xff){
    // 指数打满 特殊值 避免溢出
    return uf;
  }
  if (exp==0){
      // 非规格化的值
      frac=frac<<1;
      return sign<<31|exp<<23|frac;
  }
  // 规格化 数值*2其实就是指数+1
  return uf+(1<<23);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f. 返回浮点参数 f 的表达式 (int) f 的位级等价物。
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int sign = uf >> 31;
  int exp = (0x7f800000 & uf) >> 23;
  int bias = (1 << 7) - 1;
  int E = 0, ans = 0;
  int frac = 0x7fffff & uf;
  if (exp == 0xff) {// NaN and infinity
    return 0x80000000u;
  } else if (exp == 0) {// Denormalized value
    E = 1 - bias;
  } else {//Normalized value
    E = exp - bias;
    frac |= 0x800000;
  }
  //printf("%d %d \n", E, frac);
  if (E > 30) { // prevent left shift overflow
    return 0x80000000u;
  } else if (E > 23) {
    ans = frac << (E - 23);
  } else if (E > -9) {// prevent the right shift length from being greater than 32
    ans = frac >> (23 - E);
  }
  if (sign) {
    ans = -ans;
  }
  return ans;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *  返回等同于2^x
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // int exp = x + 127;
  // // 0
  // if (exp <= 0)
  //   return 0;
  // // INF
  // if (exp >= 0xFF)
  //   return 0x7f800000;
  // return exp << 23;
  int exp = x+127; // x是指数
  if (exp<=0){
      return 0;
  }
  if (exp>=0xff){
    // 溢出 小数为0 指数为1 表示无穷
    return 0x7f800000;
  }
  return exp<<23;
}
