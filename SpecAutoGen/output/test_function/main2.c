

/*@

ensures (a == 0) ==> (\result ==  10 / (0 + 0));

ensures (a != 0) ==> (\result ==  10 / (5 + 5));

*/

int func(int a) 
{
    int x, y;
    int sum, res;
    if (a == 0){
        x = 0; y = 0;
    }
    else {
        x = 5; y = 5;
    }
    sum = x + y; 
    res = 10/sum; 
    return res;
}
/*@

ensures (\exists int retval_66; 4 != 0 && retval_66 == 10 / (5 + 5)) ==> (\result ==  0);

*/

int main2() 
{
    int a = func(4);
    //@ assert a == 1;
    return 0;
}


/*@
requires preconditon;
requries postcondition;
*/
void hoo(*);

/*@
requires preconditon;
*/
void foo(*){

    hoo(*);

    while(*){    
        do;
    }

}


/*@
    requires preconditon;
    requries postcondition;
*/
void hoo(*);

/*@
    requires preconditon;
    requries postcondition;
*/
void foo(*){

    hoo(*);


     /*@
        loop invariant loopinv;
    */
    while(*){    
        do;
    }

}


/*@
requires preconditon;
requries postcondition;
*/
void hoo(*);

/*@
requires preconditon;
*/
void foo(*){

    hoo(*);

    /*@
    loop invariant loopinv;
    */
    while(*){    
        do;
    }

}