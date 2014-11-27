Rational number implementation.

There are implemented several operators like _+,-,/,*_, so now you can use it like that:
```C
  Rational A(1, 2);
  Rational B(3, 5);
  
  Rational C = A + B; 
  //it will produce the result of 11/10
```

  


Also, there are the overloaded operators for comparison rational numbers. You are able to use all
 kind of operators like _==, >, <, >=, <=, !=_ if you want.

There are also implemented printing function and come kind of inversion function which may be helpful
if you want invert rational number. For example:

```C
    Rational A(1,2);
    A.print_result();
    //1/2
    A.inv();
    A.print_result();
    //2
```