def linear_search(elements, target):
    for i in range(len(elements)):
        if elements[i] == target:
            return i

    return None