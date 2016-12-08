/* { dg-do compile } */
/* { dg-require-effective-target arm_arch_v8m_base_ok } */
/* { dg-add-options arm_arch_v8m_base } */
/* { dg-options "-mcmse" }  */

int __attribute__ ((cmse_nonsecure_call)) (*bar) (int);

int
foo (int a)
{
  return bar (bar (a + 1));
}

/* Checks for saving and clearing prior to function call.  */
/* { dg-final { scan-assembler "lsrs\tr4, r4, #1" } } */
/* { dg-final { scan-assembler "lsls\tr4, r4, #1" } } */
/* { dg-final { scan-assembler "movs\tr1, r4" } } */
/* { dg-final { scan-assembler "movs\tr2, r4" } } */
/* { dg-final { scan-assembler "movs\tr3, r4" } } */

/* Now we check that we use the correct intrinsic to call.  */
/* { dg-final { scan-assembler "bl\t__gnu_cmse_nonsecure_call" } } */
