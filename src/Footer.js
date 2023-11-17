const Footer = () => {
  return (
    <div className="footer">
      <div className="container">
        {/* it will follow same styling as of header*/}
        <div className="row">
          {/*it contains 4 columns col1 contains text and col2 contain image col3 contains useful links and col4 contains social media links*/}
          <div className="footer-col-1">
            <h3>Download Our App</h3>
            <p>Download App for Android and Ios mobile phone.</p>
            {/*-add images of play store and appstore in 1st column*/}
            <div className="app-logo">
              <img src={require('./img/play-store.png')} alt='PlayStore'/>
              <img src={require('./img/app-store.png')} alt='AppStore'/>
            </div>
          </div>
          <div className="footer-col-2">
            <img src={require('./img/logo-white.png')} alt='Logo White'/>
            <p>
              Our purpose is To Sustainably Make the Pleasure and Benefits of
              Sports Accessible to the Many.
            </p>
          </div>
          <div className="footer-col-3">
            <h3>Useful Links</h3>
            <ul>
              <li>Coupons</li>
              <li>Blog Post</li>
              <li>Return Policy</li>
              <li>Join Affiliate</li>
            </ul>
          </div>
          <div className="footer-col-4">
            <h3>Follow Us</h3>
            <ul>
              <li>Facebook</li>
              <li>Twitter</li>
              <li>Instagram</li>
              <li>Youtube</li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Footer;
