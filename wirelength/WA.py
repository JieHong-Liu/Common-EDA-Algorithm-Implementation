import numpy as np


def sigmaMaxX(arr, gamma):
    ans = 0
    for i in arr:
        ans += i[0] * np.exp(i[0]/gamma)
    return ans


def sigmaMinX(arr, gamma):
    ans = 0
    for i in arr:
        ans += i[0] * np.exp((-1*i[0])/gamma)
    return ans


def sigmaExpMaxX(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp(i[0]/gamma)
    return ans


def sigmaExpMinX(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp((-1 * i[0])/gamma)
    return ans


def sigmaMaxY(arr, gamma):
    ans = 0
    for i in arr:
        ans += i[1] * np.exp(i[1]/gamma)
    return ans


def sigmaMinY(arr, gamma):
    ans = 0
    for i in arr:
        ans += i[1] * np.exp((-1*i[1])/gamma)
    return ans


def sigmaExpMaxY(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp(i[1]/gamma)
    return ans


def sigmaExpMinY(arr, gamma):
    ans = 0
    for i in arr:
        ans += np.exp((-1 * i[1])/gamma)
    return ans


if __name__ == "__main__":

    gamma = 10
    arr = [[1, 25], [6, 18], [30, 5], [15, 20]]

    x1 = sigmaMaxX(arr, gamma) / sigmaExpMaxX(arr, gamma)
    x2 = sigmaMinX(arr, gamma) / sigmaExpMinX(arr, gamma)
    y1 = sigmaMaxY(arr, gamma) / sigmaExpMaxY(arr, gamma)
    y2 = sigmaMinY(arr, gamma) / sigmaExpMinY(arr, gamma)

    totalWireLength = x1 - x2 + y1 - y2

    print(totalWireLength)
