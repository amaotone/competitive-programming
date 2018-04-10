fun input() = readLine()!!.split(" ")

fun main(args: Array<String>) {
    val (N, A, B) = input().map { it.toInt() }
    println(Math.min(N * A, B))
}
