import numpy as np
import matplotlib.pyplot as plt

from scipy.integrate import quad
from scipy.optimize import minimize_scalar, brentq
from scipy.stats import norm, skew


# ============================================================
# Leitura dos dados
# ============================================================

t = np.loadtxt("decay.txt")

N = len(t)
sum_t = np.sum(t)
tau_media = np.mean(t)

print(f"N = {N}")
print(f"Media dos tempos = {tau_media:.6f} s")


# ============================================================
# Problema 1 - Histograma dos tempos de decaimento
# ============================================================

fig, ax = plt.subplots(figsize=(8, 5))

ax.hist(
    t,
    bins="fd",
    edgecolor="black",
    alpha=0.8
)

ax.set_xlabel("Tempo de decaimento t [s]")
ax.set_ylabel("Numero de eventos")
ax.set_title("Distribuicao dos tempos de decaimento")

plt.tight_layout()
plt.savefig("problema1_histograma.pdf")
plt.close()


# ============================================================
# Problema 2 - PDF exponencial
# ============================================================

def decay_pdf(x, tau):
    return (1.0 / tau) * np.exp(-x / tau)


x = np.linspace(0, 10, 1000)

fig, ax = plt.subplots(figsize=(8, 5))

for tau in [0.5, 1.0, 2.0]:
    ax.plot(
        x,
        decay_pdf(x, tau),
        label=fr"$\tau={tau}$ s"
    )

ax.set_xlabel("t [s]")
ax.set_ylabel("f(t)")
ax.set_title("PDF exponencial para diferentes valores de tau")
ax.legend()

plt.tight_layout()
plt.savefig("problema2_exponencial.pdf")
plt.close()


tau_hipotese = 2.0

prob_t_menor_1, _ = quad(
    lambda valor: decay_pdf(valor, tau_hipotese),
    0,
    1
)

print()
print("Problema 2")
print(
    f"P(t <= 1 s | tau = {tau_hipotese}) = "
    f"{prob_t_menor_1:.6f}"
)


# ============================================================
# Problema 3 - Likelihood
# ============================================================

def likelihood(tau, n, soma_t):
    return (1.0 / tau) ** n * np.exp(-soma_t / tau)


tau_grid_single = np.linspace(0.1, 4.0, 1000)

L_single = likelihood(
    tau_grid_single,
    1,
    1.0
)

fig, ax = plt.subplots(figsize=(8, 5))

ax.plot(tau_grid_single, L_single)

ax.axvline(
    1.0,
    linestyle="--",
    label=r"maximo em $\hat{\tau}=1$ s"
)

ax.set_xlabel(r"$\tau$ [s]")
ax.set_ylabel(r"$L(\tau)$")
ax.set_title("Likelihood para uma unica medida t = 1 s")
ax.legend()

plt.tight_layout()
plt.savefig("problema3_likelihood.pdf")
plt.close()


# ============================================================
# Problema 4 - Log-Likelihood e estimativa de tau
# ============================================================

def minus2logL(tau):
    if np.any(np.asarray(tau) <= 0):
        return np.inf

    return (
        2.0 * N * np.log(tau)
        + 2.0 * sum_t / tau
    )


tau_hat = tau_media

tau_grid = np.linspace(
    0.7 * tau_hat,
    1.3 * tau_hat,
    2000
)

minus2ll_values = np.array(
    [minus2logL(tau) for tau in tau_grid]
)

minimum = minus2logL(tau_hat)

fig, ax = plt.subplots(figsize=(8, 5))

ax.plot(
    tau_grid,
    minus2ll_values - minimum
)

ax.axhline(
    1.0,
    linestyle="--",
    label=r"$\Delta(-2\ln L)=1$"
)

ax.axvline(
    tau_hat,
    linestyle="--",
    label=fr"$\hat{{\tau}}={tau_hat:.4f}$ s"
)

ax.set_xlabel(r"$\tau$ [s]")
ax.set_ylabel(r"$\Delta(-2\ln L)$")
ax.set_title("Perfil da log-verossimilhanca")
ax.set_ylim(0, 10)
ax.legend()

plt.tight_layout()
plt.savefig("problema4_loglikelihood.pdf")
plt.close()


def delta_minus2logL(tau):
    return minus2logL(tau) - minimum - 1.0


tau_low = brentq(
    delta_minus2logL,
    0.5 * tau_hat,
    tau_hat
)

tau_high = brentq(
    delta_minus2logL,
    tau_hat,
    1.5 * tau_hat
)

sigma_down = tau_hat - tau_low
sigma_up = tau_high - tau_hat


print()
print("Problema 4")
print(f"tau_hat = {tau_hat:.6f} s")
print(f"sigma inferior = {sigma_down:.6f} s")
print(f"sigma superior = {sigma_up:.6f} s")


# ============================================================
# Problema 5 - Ajuste numerico de maxima verossimilhanca
# ============================================================

resultado = minimize_scalar(
    minus2logL,
    bounds=(0.1, 10.0),
    method="bounded"
)

tau_hat_numerico = resultado.x

print()
print("Problema 5")
print(
    f"tau_hat numerico = "
    f"{tau_hat_numerico:.6f} s"
)


# ============================================================
# Problema 6 - Distribuicao Gaussiana
# ============================================================

x_gauss = np.linspace(-6, 8, 1500)

fig, ax = plt.subplots(figsize=(8, 5))

parametros = [
    (0.0, 1.0),
    (2.0, 1.0),
    (0.0, 2.0),
]

for mu, sigma in parametros:
    ax.plot(
        x_gauss,
        norm.pdf(
            x_gauss,
            loc=mu,
            scale=sigma
        ),
        label=fr"$\mu={mu},\ \sigma={sigma}$"
    )

ax.set_xlabel("x")
ax.set_ylabel("f(x)")
ax.set_title("Distribuicoes Gaussianas")
ax.legend()

plt.tight_layout()
plt.savefig("problema6_gaussianas.pdf")
plt.close()


mu_x = 200.0
sigma_x = 2.0

prob_205 = norm.sf(
    205.0,
    loc=mu_x,
    scale=sigma_x
)

prob_203 = norm.sf(
    203.0,
    loc=mu_x,
    scale=sigma_x
)

prob_duas_203 = prob_203 ** 2


print()
print("Problema 6")
print(
    f"P(m >= 205 GeV) = "
    f"{prob_205:.8f} "
    f"({100 * prob_205:.4f}%)"
)

print(
    f"P(m1 >= 203 e m2 >= 203) = "
    f"{prob_duas_203:.8f} "
    f"({100 * prob_duas_203:.4f}%)"
)


# ============================================================
# Problema 7 - Teorema Central do Limite
# ============================================================

rng = np.random.default_rng(42)

n_eventos = 10000

valores_N = [3, 30, 60, 100]

resultados_tcl = {}

for n in valores_N:

    medias = np.empty(n_eventos)

    scales = np.arange(
        1,
        n + 1,
        dtype=float
    )

    for i in range(n_eventos):

        amostra = rng.exponential(
            scale=scales
        )

        medias[i] = np.mean(amostra)

    resultados_tcl[n] = medias


fig, axes = plt.subplots(
    2,
    2,
    figsize=(10, 8)
)

for ax, n in zip(
    axes.ravel(),
    valores_N
):

    dados_n = resultados_tcl[n]

    ax.hist(
        dados_n,
        bins=30,
        density=True,
        alpha=0.8,
        edgecolor="black"
    )

    media_n = np.mean(dados_n)
    sigma_n = np.std(
        dados_n,
        ddof=1
    )

    x_fit = np.linspace(
        np.min(dados_n),
        np.max(dados_n),
        500
    )

    ax.plot(
        x_fit,
        norm.pdf(
            x_fit,
            loc=media_n,
            scale=sigma_n
        )
    )

    ax.set_title(
        f"N = {n}"
    )

    ax.set_xlabel("x medio")
    ax.set_ylabel("densidade")


plt.tight_layout()
plt.savefig("problema7_tcl.pdf")
plt.close()


print()
print("Problema 7")

for n in valores_N:

    assimetria = skew(
        resultados_tcl[n]
    )

    print(
        f"N = {n}: skewness = "
        f"{assimetria:.4f}"
    )


print()
print("Execucao concluida.")
