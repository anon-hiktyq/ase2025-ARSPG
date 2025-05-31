
/*@ requires MAXPATHLEN <= 0;*/
void foo(int MAXPATHLEN,int  __BLAST_NONDET)
{
  
  int buf_off;
  int pattern_off;
  int bound_off;

 
  int glob3_pathbuf_off;
  int glob3_pathend_off;
  int glob3_pathlim_off;
  int glob3_pattern_off;
  int glob3_dc;


  buf_off = 0;
  pattern_off = 0;

  
  bound_off = 0 + (MAXPATHLEN + 1) - 1;

  glob3_pathbuf_off = buf_off;
  glob3_pathend_off = buf_off;
  glob3_pathlim_off = bound_off;
  glob3_pattern_off = pattern_off;

  glob3_dc = 0;

  
                
                /*@
          loop invariant  (\at(MAXPATHLEN, Pre) <= 0) ==> (((glob3_dc == 0)&&(glob3_pattern_off == 0)&&(glob3_pathlim_off == 0 + (\at(MAXPATHLEN, Pre) + 1) - 1)&&(glob3_pathend_off == 0)&&(glob3_pathbuf_off == 0)&&(bound_off == 0 + (\at(MAXPATHLEN, Pre) + 1) - 1)&&(pattern_off == 0)&&(buf_off == 0)&&(__BLAST_NONDET == \at(__BLAST_NONDET, Pre))&&(MAXPATHLEN == \at(MAXPATHLEN, Pre))) || (glob3_dc >= 0 && glob3_dc <= MAXPATHLEN)); 
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (glob3_pattern_off == 0);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (glob3_pathlim_off == 0 + (\at(MAXPATHLEN, Pre) + 1) - 1);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (glob3_pathend_off == 0);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (glob3_pathbuf_off == 0);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (bound_off == 0 + (\at(MAXPATHLEN, Pre) + 1) - 1);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (pattern_off == 0);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (buf_off == 0);
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (__BLAST_NONDET == \at(__BLAST_NONDET, Pre));
          loop invariant (\at(MAXPATHLEN, Pre) <= 0) ==> (MAXPATHLEN == \at(MAXPATHLEN, Pre));
                */
                for (;;){
    if (glob3_pathend_off + glob3_dc >= glob3_pathlim_off) break;
    else {
     
      glob3_dc++;
     
      /*@ assert 0 <= glob3_dc;*/
      /*@ assert glob3_dc < MAXPATHLEN + 1; */
      if (unknown()) return;
    }
}
                

}
