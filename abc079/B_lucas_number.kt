import java.util.*

fun main(args: Array<String>) {
    var sc = Scanner(System.`in`)
    var N = sc.nextInt()
    var s = 2L
    var t = 1L
    for (i in 2..N) {
        val u = s + t
        s = t
        t = u
    }
    println(t)
}