
/* >>> LOOP INVARIANT TO FILL <<< */

/*@ Inv
    ((m@pre + 1 < n@pre) => ((0 < n@pre) => (((m == m@pre)&&(n == n@pre)&&(k == k@pre)&&(j == j@pre)&&(i == 0)) || (j < n@pre && j >= 0))) ) &&
    ((m@pre + 1 < n@pre) => ((0 < n@pre) => (((m == m@pre)&&(n == n@pre)&&(k == k@pre)&&(j == j@pre)&&(i == 0)) || (j < m@pre))) ) &&
    ((m@pre + 1 < n@pre) => ((0 < n@pre) => (((m == m@pre)&&(n == n@pre)&&(k == k@pre)&&(j == j@pre)&&(i == 0)) || (k <= m@pre))) ) &&
    ((m@pre + 1 < n@pre) => ((!(0 < n@pre)) => ((m == m@pre)&&(n == n@pre)&&(k == k@pre)&&(j == j@pre)&&(i == 0)))) &&
    ((m@pre + 1 < n@pre) => (m == m@pre)) &&
    ((m@pre + 1 < n@pre) => (n == n@pre))
    */
   