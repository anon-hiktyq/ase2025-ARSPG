

/*@

ensures \result == a;

*/

int foo1(int a)
{

    return a;

}
/*@

ensures \result == 5;

*/

int main1()
{

   return foo1(5);

}