fun main(args: Array<String>) {
    val (A, B) = readLine()!!.split(" ").map { it.toDouble() }
    println(Math.round((A + B) / 2).toInt())
}
