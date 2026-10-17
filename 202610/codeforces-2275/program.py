import numpy as np

def print_mat(mat: np.ndarray):
    h, w = mat.shape[0], mat.shape[1]
    print(mat.transpose((0,2,1,3)).reshape((h**2, w**2)))
    # for row in mat:
    #     print(np.stack([row[:,x,:].flatten() for x in range(mat.shape[1])]))
    print("========================")


# def do_row(size):
#     mat = [[0 for _ in range(size)] for _ in range(size)]

#     for i in range(size):
#         for j in range(size - i):
#             for x in range(i + 1):
#                 for y in range(i + 1):
#                     mat[j + y][j + x] += 1 if i % 2 == 0 else -1
#     print_mat(mat)


def do_mat(width, height):
    # [from y/x][target y/x]
    mat = np.zeros((height, width, height, width), dtype=np.int16)

    for h in range(1, height + 1):
        for w in range(1, width + 1):
            sign = 1 if (h + w) % 2 == 0 else -1
            for y in range(0, height - h + 1):
                for x in range(0, width - w + 1):
                    for yy1 in range(y, y+h):
                        for xx1 in range(x, x+w):
                            for yy2 in range(y, y+h):
                                for xx2 in range(x, x+w):
                                    mat[yy1][xx1][yy2][xx2] += sign

    print_mat(mat)


for w in range(1, 7):
    for h in range(1, 7):
        print(f"                                [{h}, {w}]")
        do_mat(w, h)
