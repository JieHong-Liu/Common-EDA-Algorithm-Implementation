import numpy as np


def SigmaPosX(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp(i[0]/gamma)
    return ans


def SigmaNegX(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp(-i[0]/gamma)
    return ans


def SigmaPosY(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp(i[1]/gamma)
    return ans


def SigmaNegY(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp(-i[1]/gamma)
    return ans


if __name__ == "__main__":

    W = 0

    gamma = 10
    arr = [[1, 25], [6, 18], [30, 5], [15, 20]]

    x1 = SigmaPosX(arr, gamma)
    y1 = SigmaPosY(arr, gamma)
    x2 = SigmaNegX(arr, gamma)
    y2 = SigmaNegY(arr, gamma)

    W = 10*(np.log(x1)+np.log(x2)+np.log(y1)+np.log(y2))

    print(W)
