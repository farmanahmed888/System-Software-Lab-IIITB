import { Link } from "react-router-dom/cjs/react-router-dom.min";


const Homepage = () => {
    return (
        <div className="combineall">
            <div className="row">
                <div className="col-2">
                    <h1>The Openworked Sandblasted</h1>
                    <p>
                        Speake-Marins One &amp; Two Openworked Sandblasted for 2023
                        <br />
                        brings to the forefront the concepts of harmony and balance in watch
                        design.
                    </p>
                    <a href="/tmpval" className="btn">
                        Explore Now →
                    </a>
                </div>
                <div className="col-2">
                    <img src={require("./img/image1.png")} alt="header" />
                </div>
            </div>
            
            <div className="small container">
                {/*using again same row class to maintain same styling */}
                <h2 className="title">Featured Products</h2>
                <div className="row">
                    {/*this time we will make 4 columns*/}
                    {/*it contains 4 different products with heading h4, image, price <p> and rating star*/}
                    <div className="col-4">
                        <Link to="/ProductDetail">
                            <img src={require("./img/category-1.jpg")} alt="cat1" />
                        </Link>
                        {/*product img*/}
                        <Link to="/ProductDetail">
                            <h4>Watch - 1</h4>
                        </Link>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                    <div className="col-4">
                        <img src={require("./img/product-2.jpg")} alt="prod2" />
                        {/*product img*/}
                        <h4>Watch - 2</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                    <div className="col-4">
                        <img src={require("./img/product-3.jpg")} alt="prod3" />
                        {/*product img*/}
                        <h4>Watch - 3</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-half-o" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                </div>
                {/*adding latest products in class small container after featured products row*/}
                <h2 className="title">Latest Products</h2>
                <div className="row">
                    {/*this time we will make 4 columns*/}
                    {/*it contains 4 different products with heading h4, image, price <p> and rating star*/}
                    <div className="col-4">
                        <img src={require("./img/product-6.jpg")} alt="prod6" />
                        {/*product img*/}
                        <h4>Watch - 4</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                    <div className="col-4">
                        <img src={require("./img/product-7.jpg")} alt="watch6" />
                        {/*product img*/}
                        <h4>Watch - 5</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-half-o" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                    <div className="col-4">
                        <img src={require("./img/product-8.jpg")} alt="watch-8" />
                        {/*product img*/}
                        <h4>Watch - 6</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-half-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                </div>
                <div className="row">
                    <div className="col-4">
                        <img src={require("./img/product-9.jpg")} alt="watch-9" />
                        {/*product img*/}
                        <h4>Watch - 7</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                    <div className="col-4">
                        <img src={require("./img/product-11.jpg")} alt="watch-11" />
                        {/*product img*/}
                        <h4>Watch - 8</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-half-o" aria-hidden="true" />
                            <i className="fa fa-star-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                    <div className="col-4">
                        <img src={require("./img/product-12.jpg")} alt="watch-12" />
                        {/*product img*/}
                        <h4>Watch - 9</h4>
                        {/*product title*/}
                        <div className="rating">
                            {/*add stars for rating of product from font awesome 4*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star" aria-hidden="true" />
                            <i className="fa fa-star-half-o" aria-hidden="true" />
                        </div>
                        <p>$50.00</p>
                        {/*product price*/}
                    </div>
                </div>
            </div>
            <div className="offer">
                <div className="container">
                    <div className="row">
                        <div className="col-2">
                            <img src={require("./img/exclusive.png")} alt="exculive" className="offer-img" />
                        </div>
                        <div className="col-2">
                            <p>Exclusively available on Ethos</p>
                            <h1>M2/02M</h1>
                            <small>
                                M2/02M is the timeless M2/02 with a factory fitted stainless steel
                                PVD Gun metal bracelet.
                                <br />
                                The addition of the PVD gun metal stainless steel bracelet to the
                                M2/02 turns it into a definitive statement piece.
                            </small>
                            <a href="/tmp" className="btn">
                                Buy Now →
                            </a>
                            {/*where &#8594 is the code of arrow icon in explore now button*/}
                        </div>
                    </div>
                </div>
            </div>
            <div className="testimonial">
                <div className="small container">
                    {/*section*/}
                    <div className="row">
                        {/*row*/}
                        {/*3 comments*/}
                        <div className="col-3">
                            {/*3 columns*/}
                            {/*add " or left quote before comment*/}
                            <i className="fa fa-quote-left" aria-hidden="true" />
                            <p>
                                Lorem Ipsum is simply dummy text of the prinitng and typesetting
                                industry. Lorem Ipsum has been the industry;s standard dummy text
                                ever
                            </p>
                            <div className="rating">
                                {/*add stars for rating of product from font awesome 4*/}
                                <i className="fa fa-star" aria-hidden="true" />
                                {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star-half-o" aria-hidden="true" />
                            </div>
                            <img src={require("./img/user-1.png")} alt="user-1" />
                            {/*image of person*/}
                            <h3>Sean Parker</h3>
                            {/*name of person*/}
                        </div>
                        <div className="col-3">
                            {/*3 columns*/}
                            {/*add " or left quote before comment*/}
                            <i className="fa fa-quote-left" aria-hidden="true" />
                            <p>
                                Lorem Ipsum is simply dummy text of the prinitng and typesetting
                                industry. Lorem Ipsum has been the industry;s standard dummy text
                                ever
                            </p>
                            <div className="rating">
                                {/*add stars for rating of product from font awesome 4*/}
                                <i className="fa fa-star" aria-hidden="true" />
                                {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star-half-o" aria-hidden="true" />
                            </div>
                            <img src={require("./img/user-2.png")} alt="user-2" />
                            {/*image of person*/}
                            <h3>Mike Smith</h3>
                            {/*name of person*/}
                        </div>
                        <div className="col-3">
                            {/*3 columns*/}
                            {/*add " or left quote before comment*/}
                            <i className="fa fa-quote-left" aria-hidden="true" />
                            <p>
                                Lorem Ipsum is simply dummy text of the prinitng and typesetting
                                industry. Lorem Ipsum has been the industry;s standard dummy text
                                ever
                            </p>
                            <div className="rating">
                                {/*add stars for rating of product from font awesome 4*/}
                                <i className="fa fa-star" aria-hidden="true" />
                                {/*add 4 black start and one transparent star to show 4 out of 5 rating*/}
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star" aria-hidden="true" />
                                <i className="fa fa-star-half-o" aria-hidden="true" />
                            </div>
                            <img src={require("./img/user-3.png")} alt="user-3" />
                            {/*image of person*/}
                            <h3>Mable Joe</h3>
                            {/*name of person*/}
                        </div>
                    </div>
                </div>
            </div>
            <div className="brands">
                <div className="small container">
                    <div className="row">
                        <div className="col-5">
                            <img src={require("./img/logo-1.png")}alt="logo-1" />
                        </div>
                        <div className="col-5">
                            <img src={require("./img/logo-2.png")}alt="logo-2" />
                        </div>
                        <div className="col-5">
                            <img src={require("./img/logo-3.png")}alt="logo-3" />
                        </div>
                        <div className="col-5">
                            <img src={require("./img/logo-4.png")}alt="logo-4" />
                        </div>
                        <div className="col-5">
                            <img src={require("./img/logo-5.png")}alt="logo-5" />
                        </div>
                    </div>
                </div>
            </div>
        </div>
    );
};

export default Homepage;
