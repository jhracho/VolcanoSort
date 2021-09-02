def volcanoSort(s):
    # If length < 3, then you cant have a valid volcano!
    if len(s) < 3:
        return "Not a valid volcano!"

    # Order array into "Volcano Order Patent Pending"
    volcanoOrder = [float('inf')] * len(s)
    maximum = max(s)
    lindex = rindex = mindex = len(s)//2
    volcanoOrder[mindex] = maximum
    seen = [maximum]
    direction = 1
    
    for _ in range(len(s)-1):
        newMax = float('-inf')
        for num in s:
            if num not in seen:
                newMax = max(newMax, num)
        if direction == 1:
            volcanoOrder[lindex-1] = newMax
            lindex -= 1
            direction = 0
        else:
            volcanoOrder[rindex+1] = newMax
            rindex += 1
            direction = 1
        maximum = newMax
        seen.append(newMax)
    
    # Erupt the Volcano Order to create the sorted array
    volcanoSorted = []
    for _ in range(len(s)):
        volcanoSorted.append(volcanoOrder.pop(len(volcanoOrder)//2))
    return volcanoSorted[::-1]

s = [3, 5, 4, 6, 7, 8, 1, 2, 0, -1]
print(volcanoSort(s))