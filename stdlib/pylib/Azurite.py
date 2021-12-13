def add_list(L):
    result = L[0]
    for i in range(1, len(L)):
        result += L[i]
    return result


def sbt_list(L):
    result = L[0]
    for i in range(1, len(L)):
        result -= L[i]
    return result


def mtp_list(L):
    result = L[0]
    for i in range(1, len(L)):
        result *= L[i]
    return result


def div_list(L):
    result = L[0]
    for i in range(1, len(L)):
        result /= L[i] if L[i] != 0 else 1
    return result

def equal(L):
    result = True;
    index = 1;
    x = len(L) - 1
    while result and index < x:
        result = L[index-1] == L[index]
    return result

def supe(L):
    result = True;
    index = 1;
    x = len(L) - 1
    while result and index < x:
        result = L[index] > L[index-1]
    return result

def infe(L):
    result = True;
    index = 1;
    x = len(L) - 1
    while result and index < x:
        result = L[index] < L[index-1]
    return result

def supegal(L):
    result = True;
    index = 1;
    x = len(L) - 1
    while result and index < x:
        result = L[index] >= L[index-1]
    return result

def infegal(L):
    result = True;
    index = 1;
    x = len(L) - 1
    while result and index < x:
        result = L[index] <= L[index-1]
    return result

def azur_and(L):
    x = len(L)
    index = 0
    while index < x and L[x]:
        index+=1
    return index == x

def azur_or(L):
    x = len(L)
    index = 0
    while index < x and not L[x]:
        index+=1
    return L[index]

def azur_xor(L):
    nombre = 0
    first = L[0]
    index = 0
    x = len(L)
    while index < x and L[index] != first:
        index += 1
    return L[index] != first



