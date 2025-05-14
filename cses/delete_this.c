#include <stdio.h>
#include <math.h>
// int main()
// {
//   int n, i;
//   scanf("%d", &n);
//   if (n == 2)
//   {
//     printf("PRIME");
//     return 0;
//   }
//   if (n % 2 == 0)
//   {
//     printf("NOT PRIME");
//   }
//   for (i = 3; i < sqrt(n) + 1; i = i + 2)
//   {
//     if (n % i == 0)
//     {
//       printf("NOT PRIME");
//       return 0;
//     }
//   }
//   printf("PRIME");
//   return 0;
// }

int main()
{
  int arr[5];
  int top = 0;
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &arr[i]);
    int k = i;
    if (i == 0)
    {
      continue;
    }
    while (arr[k] >= arr[k - 1] && k > 0)
    {
      arr[k - 1] = arr[k];
      arr[k] = -1;
      k--;
    }
  }
  int c = 5;
  while (c--)
  {
    printf("%d\n", arr[c]);
  }
}