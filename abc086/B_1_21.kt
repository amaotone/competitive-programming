import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val a = br.readLine().replace(" ", "").toDouble()
    println(if (Math.sqrt(a)%1.0==0.0) "Yes" else "No")
}