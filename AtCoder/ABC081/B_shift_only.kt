fun main(args: Array<String>) {
    readLine()
    var A = readLine()!!.split(" ").map { it.toInt() }
    var cnt = 0
    while (A.filter { it % 2 != 0 }.size == 0) {
        cnt++
        A = A.map { it / 2 }
    }
    println(cnt)
}
