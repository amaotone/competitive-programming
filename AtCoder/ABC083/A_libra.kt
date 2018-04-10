fun main(args: Array<String>) {
    val (A, B, C, D) = readLine()!!.split(" ").map { it.toInt() }
    when {
        A + B > C + D -> println("Left")
        A + B == C + D -> println("Balanced")
        A + B < C + D -> println("Right")
    }
}
