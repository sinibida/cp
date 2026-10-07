import numpy as np

t = int(input())

for tc in range(t):
    h, w = map(int, input().split())
    mat_arr = []
    for _ in range(h):
        mat_arr.append(list(map(int, input().split())))
    mat = np.array(mat_arr, dtype=np.int16)
    print(mat[::2, ::2].sum() ** 2)
    xcalc = mat[:, ::2].sum(axis=0) * mat[:, 1::2].sum(axis=0)
    xycalc = mat[::2].sum() * mat[1::2].sum()
    print(xycalc - (mat**2).sum())
