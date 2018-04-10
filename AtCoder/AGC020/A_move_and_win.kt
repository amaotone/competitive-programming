fun main(args: Array<String>) {
    val (N, A, B) = readLine()!!.split(" ").map { it.toInt() }
    when {
        (A - B) % 2 == 0 -> println("Alice")
        else -> println("Borys")
    }
}
