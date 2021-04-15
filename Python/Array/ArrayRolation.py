def rotations0farr(a):
    first_part = n[2:]
    Arr1 = first_part.append(n[0])
    Arr2 = first_part.append(n[1])
    
    print("Leftside rotation of array: ",first_part)


n = [1,2,3,4,5,6,7,8,65]
rotations0farr(n)
'''
arr = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7

# def array_rotation():
#     arr = [1, 2, 3, 4, 5, 6, 7]
#     d, n = 2, 7
#     temp = []
#     rest_arr = []
#     for i in arr:
#         if i == d or i < d:
#             temp.append(i)
#         else:
#             rest_arr.append(i)
#
#     rest_arr.extend(temp)
#     print('rest arry =', rest_arr)
#
# array_rotation()
'''
