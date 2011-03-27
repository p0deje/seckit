<?php
/**
 * @file
 * Administrative interface for SecKit settings.
 */

/**
 * Forms administration page.
 */
function seckit_admin_form() {
  // get default/set options
  $options = _seckit_get_options();

  // main description
  $args['!browserscope'] = l(t('Browserscope'), 'http://www.browserscope.org/?category=security');
  $form['seckit_description'] = array(
    '#type' => 'item',
    '#description' => t('Module provides your website with various options to mitigate risks of common web application vulnerabilities like Cross-site Scripting, Cross-site Request Forgery and Clickjacking. It also has some options to improve your SSL/TLS security and fixes Drupal core Upload module issue leading to an easy exploitation of old Internet Explorer MIME sniffer HTML injection vulnerability. Note, that some secuirty features are not supported by all the browsers. You may find this out at !browserscope.', $args),
  );

  // main fieldset for XSS
  $form['seckit_xss'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cross-site Scripting'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#description' => t('Configure levels and various techniques of protection from cross-site scripting attacks'),
  );

  // fieldset for Content Security Policy (CSP)
  $args['!wiki'] = l(t('Mozilla Wiki'), 'https://wiki.mozilla.org/Security/CSP');
  $description = t('Content Security Policy specifies trustworthy sources of content. You may read more about it at !wiki.', $args);
  $form['seckit_xss']['csp'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content Security Policy'),
    '#tree' => TRUE,
    '#description' => $description,
  );
  // CSP enable/disable
  $form['seckit_xss']['csp']['checkbox'] = array(
    '#type' => 'checkbox',
    '#default_value' => $options['seckit_xss']['csp']['checkbox'],
    '#title' => t('X-Content-Security-Policy'),
    '#return_value' => 1,
    '#description' => t('Send X-Content-Security-Policy HTTP response header with the list of Content Security Policy directives.'),
  );
  // CSP report-only mode
  $form['seckit_xss']['csp']['report-only'] = array(
    '#type' => 'checkbox',
    '#default_value' => $options['seckit_xss']['csp']['report-only'],
    '#title' => t('Report Only'),
    '#return_value' => 1,
    '#description' => t('Use Content Security Policy in report-only mode. In this case, violations of policies will only be reported, not blocked. Use this while configuring policies. Reports are logged to watchdog.'),
  );
  // CSP description
  $items = array("'self' - allow content only from your domain", "'none' - block content from any source");
  $args['!keywords'] = theme('item_list', $items);
  $items = array('* - load content from any source', '*.example.com - load content from example.com and all its subdomains', 'example.com:* - load content from example.com via any port.  Otherwise, it will use your website default port');
  $args['!wildcards'] = theme('item_list', $items);
  $args['!spec'] = l(t('specification page'), 'https://wiki.mozilla.org/Security/CSP/Specification');
  $args['!bookmarklet'] = l(t('special bookmarklet'), 'http://brandon.sternefamily.net/posts/2010/10/content-security-policy-recommendation-bookmarklet/');
  $description = t("Set up security policy for different types of content. Don't use www prefix. Keywords are: !keywords Wildcards (*) are allowed: !wildcards More information is available at !spec. You may also use !bookmarklet to figure out necessary policies.", $args);
  $form['seckit_xss']['csp']['description'] = array(
    '#type' => 'item',
    '#title' => t('Directives'),
    '#description' => $description,
  );
  // CSP allow directive
  $form['seckit_xss']['csp']['allow'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['allow'],
    '#title' => t('allow'),
    '#description' => t("Specify security policy for all types of content, which are not specified further. Default is 'self'."),
  );
  // CSP options directive
  $items = array('inline-scripts - allow inline scripts and javascript: URI', 'eval-script - allow eval() function and allow code to be generated from strings in new Function() constructor, setTimeout() and setInterval()');
  $args['!options'] = theme('item_list', $items);
  $description = t('Set up specific security policy options. Separate options with space. Possible values are: !options', $args);
  $form['seckit_xss']['csp']['options'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['options'],
    '#title' => t('options'),
    '#description' => $description,
  );
  // CSP img-src directive
  $form['seckit_xss']['csp']['img-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['img-src'],
    '#title' => t('img-src'),
    '#description' => t('Specify trustworthy sources for &lt;img&gt; elements.'),
  );
  // CSP media-src directive
  $form['seckit_xss']['csp']['media-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['media-src'],
    '#title' => t('media-src'),
    '#description' => t('Specify trustworthy sources for &lt;audio&gt; and &lt;video&gt; elements.'),
  );
  // CSP script-src directive
  $form['seckit_xss']['csp']['script-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['script-src'],
    '#title' => t('script-src'),
    '#description' => t('Specify trustworthy sources for &lt;script&gt; elements.'),
  );
  // CSP object-src directive
  $form['seckit_xss']['csp']['object-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['object-src'],
    '#title' => t('object-src'),
    '#description' => t('Specify trustworthy sources for &lt;object&gt;, &lt;embed&gt; and &lt;applet&gt; elements.'),
  );
  // CSP frame-src directive
  $form['seckit_xss']['csp']['frame-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['frame-src'],
    '#title' => t('frame-src'),
    '#description' => t('Specify trustworthy sources for &lt;iframe&gt; and &lt;frame&gt; elements.'),
  );
  // CSP font-src directive
  $form['seckit_xss']['csp']['font-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['font-src'],
    '#title' => t('font-src'),
    '#description' => t('Specify trustworthy sources for @font-src CSS loads.'),
  );
  // CSP xhr-src directive
  $form['seckit_xss']['csp']['xhr-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['xhr-src'],
    '#title' => t('xhr-src'),
    '#description' => t('Specify trustworthy sources for XmlHttpRequest connections.'),
  );
  // CSP style-src directive
  $form['seckit_xss']['csp']['style-src'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['style-src'],
    '#title' => t('style-src'),
    '#description' => t('Specify trustworthy sources for stylesheets. Note, that inline stylesheets and style attributes of HTML elements are allowed.'),
  );
  // CSP frame-ancestors directive
  $form['seckit_xss']['csp']['frame-ancestors'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['frame-ancestors'],
    '#title' => t('frame-ancestors'),
    '#description' => t('Specify trustworthy sources to be valid ancestors for embedding your site via &lt;object&gt;, &lt;iframe&gt; and &lt;frame&gt; elements.'),
  );
  // CSP report-uri directive
  $form['seckit_xss']['csp']['report-uri'] = array(
    '#type' => 'textfield',
    '#default_value' => $options['seckit_xss']['csp']['report-uri'],
    '#title' => t('report-uri'),
    '#description' => t('Specify URI to which user-agents report CSP violations. Leave it as default unless you want another rerport place. Default is admin/settings/seckit/csp-report.'),
  );

  // fieldset for X-XSS-Protection
  $form['seckit_xss']['x_xss'] = array(
    '#type' => 'fieldset',
    '#title' => t('X-XSS-Protection'),
    '#tree' => TRUE,
    '#description' => t('X-XSS-Protection HTTP response header controls Microsoft Internet Explorer, Google Chrome and Apple Safari internal XSS filters.'),
  );
  // options for X-XSS-Protection
  $x_xss_protection_options = array(
    SECKIT_X_XSS_DISABLE => t('Disabled'),
    SECKIT_X_XSS_0 => t('0'),
    SECKIT_X_XSS_1 => t('1; mode=block'),
  );
  // configure X-XSS-Protection
  $link = l(t("IE's XSS filter security flaws in past"), 'http://hackademix.net/2009/11/21/ies-xss-filter-creates-xss-vulnerabilities');
  $items = array('Disabled - XSS filter will work in default mode', '0 - XSS filter will be disabled for a website. It may be useful because of ' . $link, '1; mode=block - XSS filter will be left enabled, but it will block entire page instead of modifying dangerous content. Enabled by default');
  $args['!values'] = theme('item_list', $items);
  $form['seckit_xss']['x_xss']['select'] = array(
    '#type' => 'select',
    '#title' => t('Configure'),
    '#options' => $x_xss_protection_options,
    '#default_value' => $options['seckit_xss']['x_xss']['select'],
    '#description' => t('!values', $args),
  );

  // fieldset for IE MIME sniffer security
  $args['!msdn'] = l(t('official blog post'), 'http://blogs.msdn.com/ie/archive/2008/07/02/ie8-security-part-v-comprehensive-protection.aspx');
  $args['!blog'] = l(t('related blog post'), 'http://p0deje.blogspot.com/2010/05/exploiting-ie-mime-sniffer.html');
  $description = t('Files of text/plain MIME type (e.g. txt) can be used to exploit Internet Explorer MIME-sniffer bug. It is recommended to restrict uploading of such files. You may read more about MIME Handling at !msdn and about its exploitation in Drupal at !blog.', $args);
  $form['seckit_xss']['ie_mime'] = array(
    '#type' => 'fieldset',
    '#title' => t('Internet Explorer MIME sniffer'),
    '#tree' => TRUE,
    '#description' => $description,
  );
  // button for fixing IE MIME sniffer exploit
  $form['seckit_xss']['ie_mime']['button'] = array(
    '#type' => 'button',
    '#prefix' => '<div id="edit-seckit-xss-ie-mime-button-ahah-wrapper">',
    '#suffix' => '</div>',
    '#ahah' => array(
      'path' => 'admin/settings/seckit/mime',
      'wrapper' => 'edit-seckit-xss-ie-mime-button-ahah-wrapper',
      'effect' => 'fade',
    ),
  );
  // set necessary state for the button
  $result = _seckit_ie_mime_check();
  if ($result == SECKIT_IE_MIME_SECURE) {
    $form['seckit_xss']['ie_mime']['button']['#value'] = t('Allow uploading of .txt files');
  }
  else {
    $form['seckit_xss']['ie_mime']['button']['#value'] = t('Restrict uploading of .txt files');
  }

  // main fieldset for CSRF
  $form['seckit_csrf'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cross-site Request Forgery'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#description' => t('Configure levels and various techniques of protection from cross-site request forgery attacks'),
  );

  // enable/disable Origin
  $form['seckit_csrf']['origin'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTTP Origin'),
    '#default_value' => $options['seckit_csrf']['origin'],
    '#description' => t('Check Origin HTTP request header.'),
  );
  // Origin whitelist
  $description = t('Comma separated list of trsutworthy sources. Do not enter your website URL - it is automatically added. Syntax of the source is: [protocol] :// [host] : [port] . E.g, http://example.com, https://example.com, https://www.example.com, http://www.example.com:8080');
  $form['seckit_csrf']['origin_whitelist'] = array(
    '#type' => 'textfield',
    '#title' => t('Allow requests from'),
    '#default_value' => $options['seckit_csrf']['origin_whitelist'],
    '#size' => 90,
    '#description' => $description,
  );

  // main fieldset for Clickjacking
  $form['seckit_clickjacking'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clickjacking'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#description' => t('Configure levels and various techniques of protection from Clickjacking/UI Redressing attacks'),
  );

  // options for X-Frame-Options
  $x_frame_options = array(
    SECKIT_X_FRAME_DISABLE => t('Disabled'),
    SECKIT_X_FRAME_SAMEORIGIN => t('SameOrigin'),
    SECKIT_X_FRAME_DENY => t('Deny'),
  );
  // configure X-Frame-Options
  $items = array('Disabled - turn off X-Frame-Options', 'SameOrigin - browser allows all the attempts of framing website within its domain. Enabled by default', 'Deny - browser rejects any attempt of framing website');
  $args['!values'] = theme('item_list', $items);
  $args['!msdn'] = l(t('MSDN article'), 'http://blogs.msdn.com/b/ie/archive/2009/01/27/ie8-security-part-vii-clickjacking-defenses.aspx');
  $description = t("X-Frame-Options HTTP response header controls browser's policy of frame rendering. Possible values: !values You may read more about it at !msdn.", $args);
  $form['seckit_clickjacking']['x_frame'] = array(
    '#type' => 'select',
    '#title' => t('X-Frame-Options'),
    '#options' => $x_frame_options,
    '#default_value' => $options['seckit_clickjacking']['x_frame'],
    '#description' => $description,
  );

  // enable/disable JS + CSS + Noscript protection
  $args['!link'] = l(t('sirdarckcat'), 'http://www.sirdarckcat.net/');
  $args['%js'] = t('seckit.document_write.js');
  $args['%write'] = t('document.write()');
  $args['%stop'] = t('stop SecKit protection');
  $args['%css'] = t('seckit.no_body.css');
  $args['%display'] = t('display: none');
  $description = t('Enable protection via JavaScript, CSS and Noscript tag. This is the most efficient Clickjacking prevention technique. If webiste is not being framed, %js starts commenting with %write and stops when reaches %stop. Thus %css, which sets body display to none, is ignored. If particularly this JavaScript file is being blocked (with XSS filter of Internet Explorer 8 or Safari), %css sets %display to body. If JavaScript is disabled within browser, it shows a special message. Credits for this trick go to !link.', $args);
  $form['seckit_clickjacking']['js_css_noscript'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable JavaScript + CSS + Noscript protection'),
    '#return_value' => 1,
    '#default_value' => $options['seckit_clickjacking']['js_css_noscript'],
    '#description' => $description,
  );

  // enable/disable styles override
  $description = t('Enable this option only if you allow users to post &lt;iframe&gt;, &lt;frame&gt;, &lt;object&gt; or &lt;embed&gt; tags. Most Clickjacking vectors use transparent frames and this stylesheet overrides opacity of iframe, frame, object and embed HTML elements to make them be always shown and also prevents "last loaded - first focused" behavior (when last loaded frame is focused regardless its z-index). Please, note that this method is not 100% proof.');
  $form['seckit_clickjacking']['override_style'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override styles for frames'),
    '#return_value' => 1,
    '#default_value' => $options['seckit_clickjacking']['override_style'],
    '#description' => $description,
  );

  // main fieldset for SSL/TLS
  $form['seckit_ssl'] = array(
    '#type' => 'fieldset',
    '#title' => t('SSL/TLS'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#description' => t('Configure various techniques to improve security of SSL/TLS'),
  );

  // enable/disable HTTP Strict Transport Security (HSTS)
  $args['!wiki'] = l(t('Wikipedia'), 'http://en.wikipedia.org/wiki/HTTP_Strict_Transport_Security');
  $form['seckit_ssl']['hsts'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTTP Strict Transport Security'),
    '#description' => t('Enable Strict-Transport-Security HTTP response header. HTTP Strict Transport Security (HSTS) header is proposed to prevent eavesdropping and man-in-the-middle attacks like SSLStrip, when a single non-HTTPS request is enough for credential theft or hijacking. It forces browser to connect to the server in HTTPS-mode only and automatically convert HTTP links into secure before sending request. !wiki has more information about HSTS', $args),
    '#default_value' => $options['seckit_ssl']['hsts'],
    '#return_value' => 1,
  );
  // HSTS max-age directive
  $form['seckit_ssl']['hsts_max_age'] = array(
    '#type' => 'textfield',
    '#title' => t('Max-Age'),
    '#description' => t('Specify Max-Age value in seconds. It sets period when user-agent should remember receipt of this header field from this server. Default is 1000.'),
    '#default_value' => $options['seckit_ssl']['hsts_max_age'],
  );
  // STS includeSubDomains directive
  $form['seckit_ssl']['hsts_subdomains'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include Subdomains'),
    '#description' => t('Force HTTP Strict Transport Security for all subdomains. If enabled, HSTS policy will be applied for all subdomains, otherwise only for the main domain.'),
    '#return_value' => 1,
    '#default_value' => $options['seckit_ssl']['hsts_subdomains'],
  );

  // validation
  $form['#validate'][] = 'seckit_admin_form_validate';

  return system_settings_form($form);
}

/**
 * Validates Content Security Policy and HTTP Strict Transport Security.
 */
function seckit_admin_form_validate($form, &$form_state) {
  // if Content Security Policy is enabled, allow directive must be specified.
  $csp_enable = $form_state['values']['seckit_xss']['csp']['checkbox'];
  $csp_allow = $form_state['values']['seckit_xss']['csp']['allow'];
  if (($csp_enable == 1) && (!$csp_allow)) {
    form_error($form['seckit_xss']['csp']['allow'], t("You have to set up Content Security Policy allow directive. Default is 'self'."));
  }
  // if HTTP Strict Transport Security is enabled, max-age must be specified.
  // HSTS max-age should only contain digits.
  $hsts_enable = $form_state['values']['seckit_ssl']['hsts'];
  $hsts_max_age = $form_state['values']['seckit_ssl']['hsts_max_age'];
  if (($hsts_enable == 1) && (!$hsts_max_age)) {
    form_error($form['seckit_ssl']['hsts_max_age'], t("You have to set up Max-Age value for HTTP Strict Transport Security. Default is 1000."));
  }
  if (preg_match('/[^0-9]/', $hsts_max_age)) {
    form_error($form['seckit_ssl']['hsts_max_age'], t('Only digits are allowed in HTTP Strict Transport Security Max-Age field.'));
  }
}