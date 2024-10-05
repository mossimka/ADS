#stack
def backsapces(s):
    result = [s[0]]
    for char in s[1:]:
        if char=='#':
            result.pop()
        else:
            result.append(char)
    return ''.join(result)

s = input().split(" ")
if (backsapces(s[0]) == backsapces(s[1])):
    print("Yes")
else:
    print("No")
