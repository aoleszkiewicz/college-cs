def bubble_sort(nums: list[int]) -> list[int]:
    for _ in range(0, len(nums)):
        for j in range(0, len(nums) - 1):
            if nums[j] > nums[j + 1]:
                # The greater value is acting as a "bubble" and is being swapped
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
    return nums

print(bubble_sort([1, 3, 7, 4, 2, 8, 10]))