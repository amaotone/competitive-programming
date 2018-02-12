fun main(args: Array<String>) {
    val s = readLine()!!
    var (x, y) = readLine()!!.split(" ").map { it.toInt() }
    val t = s.split("T").map { it.length }
    val xs = t.filterIndexed { id, v -> id % 2 == 0 }
    val ys = t.filterIndexed { id, v -> id % 2 != 0 }
    var xSet = setOf(xs[0])
    var ySet = setOf(0)
    for ((i, d) in xs.withIndex()) {
        if (i == 0) continue
        xSet = xSet.toList().map { listOf(it - d, it + d) }.flatten().toSet()
    }
    for ((i, d) in ys.withIndex()) {
        ySet = ySet.toList().map { listOf(it - d, it + d) }.flatten().toSet()
    }
    println(if (x in xSet && y in ySet) "Yes" else "No")
}
