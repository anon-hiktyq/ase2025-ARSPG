
int unknown();


void foo() {


  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;


  while(unknown()){
  	if(w) {
  	  x++;
  	  w = !w;
	  }
	
    if(!z) {
      y++; 
      z=!z;
    }
  }

  /*@ assert x == y; */
  
}
