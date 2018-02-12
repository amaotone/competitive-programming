fun main(args: Array<String>) {
    var (X, Y) = readLine()!!.split(" ").map { it.toLong() }
    var cnt = 0
    while (X <= Y) {
        X *= 2
        cnt++
    }
    println(cnt)
}
