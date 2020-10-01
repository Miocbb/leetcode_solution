import heapq

class Solution:
    def is_overlap(self, s1, s2):
        return (s1[0] <= s2[0] < s1[1]) or (s1[0] < s2[1] <= s1[1]) or (s2[0] <= s1[0] and s2[1] >= s1[1])

    def join(self, room, s):
        for i in room:
            if self.is_overlap(s, i):
                return False
        return True

    def minMeetingRooms_wrong(self, intervals) -> int:
        """
        This design will have problems when there are two meetings happend and
        last the same time, e.g. [[1, 2], [1, 2], [10, 12], [6, 8],[7, 11].
        There will be two valid arrangement based on this algorithm.
        1.
        room 1: [1, 2], [6, 8], [10, 12]
        room 2: [1, 2], [7, 11]
        2.
        room 1: [1, 2], [6, 8]
        room 2: [1, 2], [10, 12]
        room 3: [7, 11]
        """
        intervals.sort(key=lambda x : x[0])
        if len(intervals) == 0:
            return 0
        rooms = []
        rooms.append([intervals[0]])
        for n in range(1, len(intervals)):
            sn = intervals[n]
            new_room = True
            for room in rooms:
                if self.join(room, sn):
                    room.append(sn)
                    new_room = False
                    break
            if new_room:
                rooms.append([sn])
        return len(rooms)

    def minMeetingRooms(self, intervals) -> int:
        if len(intervals) == 0:
            return 0
        # simulate the real life. Meeting takes place by the increasing order
        # of starting time. Only allocate new room unless it is necessary.
        intervals.sort(key=lambda x : x[0])
        rooms = [intervals[0][1]]
        for n in range(1, len(intervals)):
            # free the room that ends earliest based on the min-heap.
            if rooms[0] <= intervals[n][0]:
                heapq.heappop(rooms)

            # maintain the min-heap with heappush
            heapq.heappush(rooms, intervals[n][1])
        return len(rooms)

intervals = [[3, 30],[1, 3]]
intervals = [[9,10],[4,9],[4,17]]
intervals = [[1,5],[8,9],[8,9]]
print(Solution().minMeetingRooms(intervals))
print(Solution().is_overlap([0, 30], [5, 10]))
