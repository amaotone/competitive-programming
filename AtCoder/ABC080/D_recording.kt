// 貪欲
import java.util.*

fun main(args: Array<String>) {
    var sc = Scanner(System.`in`)
    val N = sc.nextInt()
    val C = sc.nextInt()
    var order = Array(N, {
        (1..3).map { sc.nextInt() }
    })
    order.sortBy { it[0] }
    var searched: MutableSet<Int> = mutableSetOf()
    var ans = 0
    for (i in 0..N - 1) {
        if (i in searched) continue
        ans += 1
        var prev = order[i]
        for ((id, next) in order.withIndex().filter { it.index !in searched }) {
            if ((prev[2] == next[2] && next[0] >= prev[1]) || (prev[2] != next[2] && next[0].toDouble() - 0.5 >= prev[1].toDouble())) {
                searched.add(id)
                prev = next
            }
        }
    }
    println(ans)
}
