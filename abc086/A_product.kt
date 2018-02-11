import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (a, b) = br.readLine().split(' ').map { it.toInt() }
    val c = a*b
    println(if (c%2 == 0) "Even" else "Odd")
}