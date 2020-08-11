/*
    survHE is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    survHE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with survHE.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0

#include <stan/model/model_header.hpp>

namespace model_PolyWeibull_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_PolyWeibull");
    reader.add_event(106, 104, "end", "model_PolyWeibull");
    return reader;
}

template <bool propto, typename T0__, typename T1__, typename T2__, typename T3__>
typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
polyweibull_lpdf(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& t,
                     const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& d,
                     const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& shape,
                     const Eigen::Matrix<T3__, Eigen::Dynamic, Eigen::Dynamic>& rate,
                     const int& M, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 52;
        validate_non_negative_index("h", "num_elements(t)", num_elements(t));
        validate_non_negative_index("h", "M", M);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> h(num_elements(t), M);
        stan::math::initialize(h, DUMMY_VAR__);
        stan::math::fill(h, DUMMY_VAR__);

        current_statement_begin__ = 53;
        validate_non_negative_index("log_S", "num_elements(t)", num_elements(t));
        validate_non_negative_index("log_S", "M", M);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> log_S(num_elements(t), M);
        stan::math::initialize(log_S, DUMMY_VAR__);
        stan::math::fill(log_S, DUMMY_VAR__);

        current_statement_begin__ = 54;
        validate_non_negative_index("log_lik", "num_elements(t)", num_elements(t));
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> log_lik(num_elements(t));
        stan::math::initialize(log_lik, DUMMY_VAR__);
        stan::math::fill(log_lik, DUMMY_VAR__);

        current_statement_begin__ = 55;
        local_scalar_t__ prob(DUMMY_VAR__);
        (void) prob;  // dummy to suppress unused var warning
        stan::math::initialize(prob, DUMMY_VAR__);
        stan::math::fill(prob, DUMMY_VAR__);


        current_statement_begin__ = 56;
        for (int j = 1; j <= M; ++j) {

            current_statement_begin__ = 57;
            for (int i = 1; i <= num_elements(t); ++i) {

                current_statement_begin__ = 58;
                stan::model::assign(h, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(j), stan::model::nil_index_list())), 
                            ((get_base1(shape, j, "shape", 1) * get_base1(rate, i, j, "rate", 1)) * pow(get_base1(t, i, "t", 1), (get_base1(shape, j, "shape", 1) - 1))), 
                            "assigning variable h");
                current_statement_begin__ = 59;
                stan::model::assign(log_S, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(j), stan::model::nil_index_list())), 
                            (get_base1(rate, i, j, "rate", 1) * pow(get_base1(t, i, "t", 1), get_base1(shape, j, "shape", 1))), 
                            "assigning variable log_S");
            }
        }
        current_statement_begin__ = 62;
        for (int i = 1; i <= num_elements(t); ++i) {

            current_statement_begin__ = 63;
            stan::model::assign(log_lik, 
                        stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                        ((get_base1(d, i, "d", 1) * stan::math::log(sum(stan::model::rvalue(h, stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "h")))) - sum(stan::model::rvalue(log_S, stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "log_S"))), 
                        "assigning variable log_lik");
        }
        current_statement_begin__ = 65;
        stan::math::assign(prob, sum(log_lik));
        current_statement_begin__ = 66;
        return stan::math::promote_scalar<fun_return_scalar_t__>(prob);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
template <typename T0__, typename T1__, typename T2__, typename T3__>
typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
polyweibull_lpdf(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& t,
                     const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& d,
                     const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& shape,
                     const Eigen::Matrix<T3__, Eigen::Dynamic, Eigen::Dynamic>& rate,
                     const int& M, std::ostream* pstream__) {
    return polyweibull_lpdf<false>(t,d,shape,rate,M, pstream__);
}


struct polyweibull_lpdf_functor__ {
    template <bool propto, typename T0__, typename T1__, typename T2__, typename T3__>
        typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
    operator()(const Eigen::Matrix<T0__, Eigen::Dynamic, 1>& t,
                     const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& d,
                     const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& shape,
                     const Eigen::Matrix<T3__, Eigen::Dynamic, Eigen::Dynamic>& rate,
                     const int& M, std::ostream* pstream__) const {
        return polyweibull_lpdf(t, d, shape, rate, M, pstream__);
    }
};

class model_PolyWeibull
  : public stan::model::model_base_crtp<model_PolyWeibull> {
private:
        int n;
        vector_d t;
        vector_d d;
        int H;
        int M;
        std::vector<matrix_d> X;
        matrix_d mu_beta;
        matrix_d sigma_beta;
public:
    model_PolyWeibull(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_PolyWeibull(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_PolyWeibull_namespace::model_PolyWeibull";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 72;
            context__.validate_dims("data initialization", "n", "int", context__.to_vec());
            n = int(0);
            vals_i__ = context__.vals_i("n");
            pos__ = 0;
            n = vals_i__[pos__++];

            current_statement_begin__ = 73;
            validate_non_negative_index("t", "n", n);
            context__.validate_dims("data initialization", "t", "vector_d", context__.to_vec(n));
            t = Eigen::Matrix<double, Eigen::Dynamic, 1>(n);
            vals_r__ = context__.vals_r("t");
            pos__ = 0;
            size_t t_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < t_j_1_max__; ++j_1__) {
                t(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 74;
            validate_non_negative_index("d", "n", n);
            context__.validate_dims("data initialization", "d", "vector_d", context__.to_vec(n));
            d = Eigen::Matrix<double, Eigen::Dynamic, 1>(n);
            vals_r__ = context__.vals_r("d");
            pos__ = 0;
            size_t d_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < d_j_1_max__; ++j_1__) {
                d(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 75;
            context__.validate_dims("data initialization", "H", "int", context__.to_vec());
            H = int(0);
            vals_i__ = context__.vals_i("H");
            pos__ = 0;
            H = vals_i__[pos__++];
            check_greater_or_equal(function__, "H", H, 2);

            current_statement_begin__ = 76;
            context__.validate_dims("data initialization", "M", "int", context__.to_vec());
            M = int(0);
            vals_i__ = context__.vals_i("M");
            pos__ = 0;
            M = vals_i__[pos__++];
            check_greater_or_equal(function__, "M", M, 2);

            current_statement_begin__ = 77;
            validate_non_negative_index("X", "n", n);
            validate_non_negative_index("X", "H", H);
            validate_non_negative_index("X", "M", M);
            context__.validate_dims("data initialization", "X", "matrix_d", context__.to_vec(M,n,H));
            X = std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> >(M, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(n, H));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_j_2_max__ = H;
            size_t X_j_1_max__ = n;
            size_t X_k_0_max__ = M;
            for (size_t j_2__ = 0; j_2__ < X_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < X_j_1_max__; ++j_1__) {
                    for (size_t k_0__ = 0; k_0__ < X_k_0_max__; ++k_0__) {
                        X[k_0__](j_1__, j_2__) = vals_r__[pos__++];
                    }
                }
            }

            current_statement_begin__ = 78;
            validate_non_negative_index("mu_beta", "H", H);
            validate_non_negative_index("mu_beta", "M", M);
            context__.validate_dims("data initialization", "mu_beta", "matrix_d", context__.to_vec(H,M));
            mu_beta = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(H, M);
            vals_r__ = context__.vals_r("mu_beta");
            pos__ = 0;
            size_t mu_beta_j_2_max__ = M;
            size_t mu_beta_j_1_max__ = H;
            for (size_t j_2__ = 0; j_2__ < mu_beta_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < mu_beta_j_1_max__; ++j_1__) {
                    mu_beta(j_1__, j_2__) = vals_r__[pos__++];
                }
            }

            current_statement_begin__ = 79;
            validate_non_negative_index("sigma_beta", "H", H);
            validate_non_negative_index("sigma_beta", "M", M);
            context__.validate_dims("data initialization", "sigma_beta", "matrix_d", context__.to_vec(H,M));
            sigma_beta = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(H, M);
            vals_r__ = context__.vals_r("sigma_beta");
            pos__ = 0;
            size_t sigma_beta_j_2_max__ = M;
            size_t sigma_beta_j_1_max__ = H;
            for (size_t j_2__ = 0; j_2__ < sigma_beta_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < sigma_beta_j_1_max__; ++j_1__) {
                    sigma_beta(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            check_greater_or_equal(function__, "sigma_beta", sigma_beta, 0);


            // initialize transformed data variables
            // execute transformed data statements

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 83;
            validate_non_negative_index("beta", "H", H);
            validate_non_negative_index("beta", "M", M);
            num_params_r__ += (H * M);
            current_statement_begin__ = 84;
            validate_non_negative_index("alpha", "M", M);
            num_params_r__ += M;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_PolyWeibull() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 83;
        if (!(context__.contains_r("beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "H", H);
        validate_non_negative_index("beta", "M", M);
        context__.validate_dims("parameter initialization", "beta", "vector_d", context__.to_vec(M,H));
        std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > beta(M, Eigen::Matrix<double, Eigen::Dynamic, 1>(H));
        size_t beta_j_1_max__ = H;
        size_t beta_k_0_max__ = M;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < beta_k_0_max__; ++k_0__) {
                beta[k_0__](j_1__) = vals_r__[pos__++];
            }
        }
        size_t beta_i_0_max__ = M;
        for (size_t i_0__ = 0; i_0__ < beta_i_0_max__; ++i_0__) {
            try {
                writer__.vector_unconstrain(beta[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }

        current_statement_begin__ = 84;
        if (!(context__.contains_r("alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        validate_non_negative_index("alpha", "M", M);
        context__.validate_dims("parameter initialization", "alpha", "vector_d", context__.to_vec(M));
        Eigen::Matrix<double, Eigen::Dynamic, 1> alpha(M);
        size_t alpha_j_1_max__ = M;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            alpha(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.positive_ordered_unconstrain(alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable alpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 83;
            std::vector<Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> > beta;
            size_t beta_d_0_max__ = M;
            beta.reserve(beta_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < beta_d_0_max__; ++d_0__) {
                if (jacobian__)
                    beta.push_back(in__.vector_constrain(H, lp__));
                else
                    beta.push_back(in__.vector_constrain(H));
            }

            current_statement_begin__ = 84;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.positive_ordered_constrain(M, lp__);
            else
                alpha = in__.positive_ordered_constrain(M);

            // transformed parameters
            current_statement_begin__ = 88;
            validate_non_negative_index("loglambda", "n", n);
            validate_non_negative_index("loglambda", "M", M);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> loglambda(n, M);
            stan::math::initialize(loglambda, DUMMY_VAR__);
            stan::math::fill(loglambda, DUMMY_VAR__);

            current_statement_begin__ = 89;
            validate_non_negative_index("lambda", "n", n);
            validate_non_negative_index("lambda", "M", M);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> lambda(n, M);
            stan::math::initialize(lambda, DUMMY_VAR__);
            stan::math::fill(lambda, DUMMY_VAR__);

            // transformed parameters block statements
            current_statement_begin__ = 90;
            for (int m = 1; m <= M; ++m) {

                current_statement_begin__ = 91;
                stan::model::assign(loglambda, 
                            stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list())), 
                            multiply(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_uni(m), stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list()))), "X"), stan::model::rvalue(beta, stan::model::cons_list(stan::model::index_uni(m), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "beta")), 
                            "assigning variable loglambda");
                current_statement_begin__ = 92;
                for (int i = 1; i <= n; ++i) {

                    current_statement_begin__ = 93;
                    stan::model::assign(lambda, 
                                stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list())), 
                                stan::math::exp(get_base1(loglambda, i, m, "loglambda", 1)), 
                                "assigning variable lambda");
                }
            }

            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            current_statement_begin__ = 88;
            size_t loglambda_j_1_max__ = n;
            size_t loglambda_j_2_max__ = M;
            for (size_t j_1__ = 0; j_1__ < loglambda_j_1_max__; ++j_1__) {
                for (size_t j_2__ = 0; j_2__ < loglambda_j_2_max__; ++j_2__) {
                    if (stan::math::is_uninitialized(loglambda(j_1__, j_2__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: loglambda" << "(" << j_1__ << ", " << j_2__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable loglambda: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }
            current_statement_begin__ = 89;
            size_t lambda_j_1_max__ = n;
            size_t lambda_j_2_max__ = M;
            for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
                    if (stan::math::is_uninitialized(lambda(j_1__, j_2__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: lambda" << "(" << j_1__ << ", " << j_2__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable lambda: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }

            // model body

            current_statement_begin__ = 100;
            for (int m = 1; m <= M; ++m) {

                current_statement_begin__ = 101;
                lp_accum__.add(normal_log<propto__>(stan::model::rvalue(beta, stan::model::cons_list(stan::model::index_uni(m), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "beta"), stan::model::rvalue(mu_beta, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list())), "mu_beta"), stan::model::rvalue(sigma_beta, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list())), "sigma_beta")));
            }
            current_statement_begin__ = 103;
            lp_accum__.add(polyweibull_lpdf<propto__>(t, d, alpha, lambda, M, pstream__));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("beta");
        names__.push_back("alpha");
        names__.push_back("loglambda");
        names__.push_back("lambda");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(M);
        dims__.push_back(H);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(M);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dims__.push_back(M);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dims__.push_back(M);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_PolyWeibull_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > beta;
        size_t beta_d_0_max__ = M;
        beta.reserve(beta_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < beta_d_0_max__; ++d_0__) {
            beta.push_back(in__.vector_constrain(H));
        }
        size_t beta_j_1_max__ = H;
        size_t beta_k_0_max__ = M;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < beta_k_0_max__; ++k_0__) {
                vars__.push_back(beta[k_0__](j_1__));
            }
        }

        Eigen::Matrix<double, Eigen::Dynamic, 1> alpha = in__.positive_ordered_constrain(M);
        size_t alpha_j_1_max__ = M;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            vars__.push_back(alpha(j_1__));
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            // declare and define transformed parameters
            current_statement_begin__ = 88;
            validate_non_negative_index("loglambda", "n", n);
            validate_non_negative_index("loglambda", "M", M);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> loglambda(n, M);
            stan::math::initialize(loglambda, DUMMY_VAR__);
            stan::math::fill(loglambda, DUMMY_VAR__);

            current_statement_begin__ = 89;
            validate_non_negative_index("lambda", "n", n);
            validate_non_negative_index("lambda", "M", M);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> lambda(n, M);
            stan::math::initialize(lambda, DUMMY_VAR__);
            stan::math::fill(lambda, DUMMY_VAR__);

            // do transformed parameters statements
            current_statement_begin__ = 90;
            for (int m = 1; m <= M; ++m) {

                current_statement_begin__ = 91;
                stan::model::assign(loglambda, 
                            stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list())), 
                            multiply(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_uni(m), stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list()))), "X"), stan::model::rvalue(beta, stan::model::cons_list(stan::model::index_uni(m), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list())), "beta")), 
                            "assigning variable loglambda");
                current_statement_begin__ = 92;
                for (int i = 1; i <= n; ++i) {

                    current_statement_begin__ = 93;
                    stan::model::assign(lambda, 
                                stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(m), stan::model::nil_index_list())), 
                                stan::math::exp(get_base1(loglambda, i, m, "loglambda", 1)), 
                                "assigning variable lambda");
                }
            }

            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // write transformed parameters
            if (include_tparams__) {
                size_t loglambda_j_2_max__ = M;
                size_t loglambda_j_1_max__ = n;
                for (size_t j_2__ = 0; j_2__ < loglambda_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < loglambda_j_1_max__; ++j_1__) {
                        vars__.push_back(loglambda(j_1__, j_2__));
                    }
                }
                size_t lambda_j_2_max__ = M;
                size_t lambda_j_1_max__ = n;
                for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                        vars__.push_back(lambda(j_1__, j_2__));
                    }
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    std::string model_name() const {
        return "model_PolyWeibull";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t beta_j_1_max__ = H;
        size_t beta_k_0_max__ = M;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < beta_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "beta" << '.' << k_0__ + 1 << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t alpha_j_1_max__ = M;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t loglambda_j_2_max__ = M;
            size_t loglambda_j_1_max__ = n;
            for (size_t j_2__ = 0; j_2__ < loglambda_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < loglambda_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "loglambda" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
            size_t lambda_j_2_max__ = M;
            size_t lambda_j_1_max__ = n;
            for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "lambda" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t beta_j_1_max__ = H;
        size_t beta_k_0_max__ = M;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            for (size_t k_0__ = 0; k_0__ < beta_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "beta" << '.' << k_0__ + 1 << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        size_t alpha_j_1_max__ = M;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t loglambda_j_2_max__ = M;
            size_t loglambda_j_1_max__ = n;
            for (size_t j_2__ = 0; j_2__ < loglambda_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < loglambda_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "loglambda" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
            size_t lambda_j_2_max__ = M;
            size_t lambda_j_1_max__ = n;
            for (size_t j_2__ = 0; j_2__ < lambda_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "lambda" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }

        if (!include_gqs__) return;
    }

}; // model

}  // namespace

typedef model_PolyWeibull_namespace::model_PolyWeibull stan_model;

#ifndef USING_R

stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

#endif


#endif
