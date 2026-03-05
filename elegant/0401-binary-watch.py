class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        return [f"{h}:{m:02}" for h, m in product(range(12), range(60)) if h.bit_count() + m.bit_count() == turnedOn]
