fun main(args: Array<String>) {
    val (N, A, B) = readLine()!!.split(" ").map { it.toInt() }
    var sum = 0
    for (i in 1..N) {
        var t = 0
        for (c in i.toString()) {
            t += c.toString().toInt()
        }
        if (t >= A && t <= B) sum += i
    }
    println(sum)
}
