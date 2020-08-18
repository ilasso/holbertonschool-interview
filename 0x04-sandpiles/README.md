# **Sandpiles**

## *Function that computes the sum of two sandpiles*

## **Invoke**

```
sandpiles_sum(grid1, grid2);
```


Where:
```
int grid1[3][3], int grid2[3][3]
```
## **Output**

In grid1 there is the result of adding grid1 and grid2, if grid1 is stable, then that will be the result, if it is not stable, the algorithm is applied until the resulting matrix is ​​stable, destroying all cells that have more than 3 grains

### Examples
```
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
=
3 3 3
3 3 3
3 3 3
```
```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

## **Compiling**
```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

## **Usage**

```
./sandpiles
```
## Scope

>* Ubuntu 14.04 LTS
> * Compiled with gcc 4.8.4
> * grid1 and grid2 are individually stable
> * A sandpile is considered stable when none of its cells contains more than 3 grains
> * When the function is done, grid1 must be stable
> * grid1 must be printed before each toppling round, only if it is unstable

## Author

**Ivan Dario Lasso Gil** - :email: [Email](mailto:ivan-dario.lasso-gil@holbertonschool.com)


## Licence

Public Domain. No copy write protection.
