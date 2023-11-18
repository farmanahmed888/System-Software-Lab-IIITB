import { useState,useEffect } from "react";
import WatchList from "./WatchList";

const Products = () => {
    const [watches, setWatches] = useState([
        { title: 'My first Watch', body: 'lorem', cost: 'mario', id: 1 },
        { title: 'My second Watch', body: 'lorem', cost: 'mario', id: 2 },
        { title: 'My third Watch', body: 'lorem', cost: 'mario', id: 3 }
    ]);
    return (
        <div className="Products">
            <div className="small container">
                {/*we have create an another row to add title and give user dropdown list with four options so they can select what they want*/}
                <div className="row row-2">
                    <h2>All Products</h2>
                </div>
                <WatchList watches={watches}></WatchList>
                {/*This is the same class which already have index.html consisting of 4 columns*/}
                <div className="row">
                    {/*this time we will make 4 columns*/}
                    {/*it contains 4 different products with heading h4, image, price <p> and rating star*/}
                    <div className="col-4">
                        <img src={require("./img/product-1.jpg")} alt="product-1" />
                        {/*product img*/}
                        <h4>Product 1</h4>
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
                        <img src={require("./img/product-2.jpg")} alt="product-2" />
                        {/*product img*/}
                        <h4>Product 2</h4>
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
                        <img src={require("./img/product-3.jpg")} alt="product-3" />
                        {/*product img*/}
                        <h4>Product 3</h4>
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
                {/*above are the products of featured prodcuts row, as the page is for all products, so I have added latest products row too here  */}
                <div className="row">
                    {/*this time we will make 4 columns*/}
                    {/*it contains 4 different products with heading h4, image, price <p> and rating star*/}
                    <div className="col-4">
                        <img src={require("./img/product-5.jpg")} alt="product-4" />
                        {/*product img*/}
                        <h4>Product 4</h4>
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
                        <img src={require("./img/product-6.jpg")} alt="product-6" />
                        {/*product img*/}
                        <h4>Product 5</h4>
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
                        <img src={require("./img/product-7.jpg")} alt="product-7" />
                        {/*product img*/}
                        <h4>Product 6</h4>
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
                <div className="row">
                    <div className="col-4">
                        <img src={require("./img/product-8.jpg")} alt="product-8" />
                        {/*product img*/}
                        <h4>Product 7</h4>
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
                        <img src={require("./img/product-10.jpg")} alt="product-10" />
                        {/*product img*/}
                        <h4>Product 8</h4>
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
                        <img src={require("./img/product-11.jpg")} alt="product-11" />
                        {/*product img*/}
                        <h4>Product 9</h4>
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
            </div>
        </div>
    );
}

export default Products;