fun main(args: Array<String>) {
    var (N, H) = readLine()!!.split(" ").map{it.toInt()}
    var A = IntArray(N, {0})
    var B = IntArray(N, {0})
    for (i in 0..N-1) {
        var (a, b) = readLine()!!.split(" ").map{it.toInt()}
        A[i] = a
        B[i] = b
    }
    val amax = A.max()!!
    val Bsort = B.sortedDescending()
    var damage = 0
    var cnt = 0
    for (b in Bsort) {
        if (b < amax) break
        damage += b
        cnt ++
        if (damage >= H) {
            println(cnt)
            return
        }
    }
    println(cnt+(H-damage-1)/amax+1)
}
